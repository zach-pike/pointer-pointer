#include "raylib.h"

typedef struct {
    Texture2D texture;
    Vector2 pos;
    float rot;
} Pointer;

//Point to location
void PointTo(Pointer* pointer, Vector2 to, bool showExtras);

//pointer maker function
Pointer PointerHelper(Vector2 location, Texture2D texture);