#include "image.h"

Image::Image()
{
    this->clip_rect = { 0, 0, 0, 0 };
    this->is_clipped = false;
}

Image::Image(string path)
{
    this->SetTexture(path);
    this->clip_rect = { 0, 0, 0, 0 };
    this->is_clipped = false;
}

Image::~Image()
{
    delete(&this->clip_rect);
}

void Image::Render()
{
    if( !this->is_clipped)
    {
        SDL_RenderCopy(System::Renderer, this->texture, NULL, &this->rect);
    }
    else
    {
       SDL_RenderCopy(System::Renderer, this->texture, &this->clip_rect, &this->rect);
    }
}

void Image::Clip(int x, int y, int w, int h)
{
    this->clip_rect.x = x;
    this->clip_rect.y = y;
    this->clip_rect.w = w;
    this->clip_rect.h = h;
    this->rect.w = w;
    this->rect.h = h;
    this->is_clipped = true;
}
void Image::SetClipX(int x)
{
    this->clip_rect.x = x;
    this->is_clipped = true;
}
void Image::SetClipY(int y)
{
    this->clip_rect.y = y;
    this->is_clipped = true;
}
void Image::SetClipWidth(int width)
{
    this->clip_rect.w = width;
    this->rect.w = width;
    this->is_clipped = true;
}
void Image::SetClipHeight(int height)
{
    this->clip_rect.h = height;
    this->rect.h = height;
    this->is_clipped = true;
}

int Image::GetClipX()       { return this->clip_rect.x; }
int Image::GetClipY()       { return this->clip_rect.y; }
int Image::GetClipWidth()   { return this->clip_rect.w; }
int Image::GetClipHeight()  { return this->clip_rect.h; }
