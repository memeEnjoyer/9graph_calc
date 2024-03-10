#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1280;
// Can you do that? Should you do that? I don't know, but I did.
// TODO: return renderer to main without making it global
SDL_Window* gWindow = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                       SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
int middlePoint[2]; // Middle coordinates but aligned to the grid
/*

Poor logic + not following KISS
Tried to implement a higher order procedure
Failed :(

int fastCheck(bool isVertical, int i, int border) {
    if(isVertical)
      return i;
    else
      return border;
  };

void drawLines(int border, bool isVertical) {
  int side = 20;
  for(int i = side; i < border; i+=side) {
    SDL_RenderDrawLine(gRenderer, isVertical*i, (!isVertical)*i,
                       fastCheck(isVertical, i, border), fastCheck(!isVertical, i, border));
    if(i <= border/2)
      middlePoint[isVertical] = i; // If drawing vertical lines, computes middle x, else y
  }
}
*/
SDL_Window* createCalcWindow() {
  //Creating SDL window
  if(gWindow == NULL) {
    printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
  }

  // Draw x and y axises
  int side = 20;
  SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
  SDL_RenderClear(gRenderer);
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);  
  for(int i = 0; i < SCREEN_WIDTH; i+=side) {
    SDL_RenderDrawLine(gRenderer, i, 0, i, SCREEN_HEIGHT);
    if(i <= SCREEN_WIDTH/2)
      middlePoint[0] = i;
  }
  for(int i = 0; i < SCREEN_HEIGHT; i+=side) {
    SDL_RenderDrawLine(gRenderer, 0, i, SCREEN_WIDTH, i);
    if(i <= SCREEN_HEIGHT/2)
      middlePoint[1] = i;
  }
  // ^ redo, make a higher order procedure to exclude repetition(bad idea)

  printf("middle x: %d, middle y: %d", middlePoint[0], middlePoint[1]);

  return gWindow;
}
