#include "flecs.h"
#include "raylib.h"
#include "net/net_constants.h"
#include "entity.h"

ecs_world_t *world; // the world

ecs_entity_t players[MAX_PLAYERS];

void InitWorld() {
    world = ecs_init();

    ECS_COMPONENT(world, Transform);
    ECS_COMPONENT(world, Color);
}

void DeinitWorld() {
    ecs_fini(world);
}

void AddPlayer(int id, Vector3 pos, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    players[id] = ecs_new_id(world);
    ecs_set(world, e, Transform, {{pos.x, pos.y, pos.z}, {0.0f, 0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}});
    ecs_set(world, e, Color, {r, g, b, a});
}