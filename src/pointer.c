#include "pointer.h"
#include "raylib.h"
#include "stdlib.h"
#include <math.h>
#include "stdio.h"

Pointer PointerHelper(Vector2 location, Texture2D texture) {
    Pointer obj;

    //set position
    obj.pos = location;

    //set rect
    obj.texture = texture;

    //set rot
    obj.rot = 0.0f;


    return obj;
}

//oh god the trigometry
void PointTo(Pointer* pointer, Vector2 to, bool showExtras) {
    if (showExtras) {
        //show line going down (Leg 1)
        DrawLineEx((Vector2) { pointer->pos.x, pointer->pos.y }, (Vector2) { pointer->pos.x, to.y }, 3, BLUE);

        //draw leg 2
        DrawLineEx((Vector2) { pointer->pos.x, to.y }, to, 3, ORANGE);

        //draw hypotenuse
        DrawLineEx((Vector2) { pointer->pos.x, pointer->pos.y }, to, 3, YELLOW);
    }

    //get triangle legs
    float a = to.y - pointer->pos.y;
    float leg = to.x - pointer->pos.x;

    //get the hypotenuse
    float h = sqrt(pow(a, 2) + pow(leg, 2));

    //calculate the angle using trig
    float deg = acos(a/h)*RAD2DEG;

    //fix negative x
    if (pointer->pos.x < to.x) {
        deg *=-1;
    }

    //set rotation
    pointer->rot = deg;

    //draw pointer
    DrawTexturePro(pointer->texture, 
                   (Rectangle) { 0.0f, 0.0f, pointer->texture.width, pointer->texture.height },
                   (Rectangle) { pointer->pos.x, pointer->pos.y, pointer->texture.width, pointer->texture.height },
                   (Vector2) { pointer->texture.width / 2, pointer->texture.height /2 },
                   pointer->rot,
                   WHITE
                  );
}