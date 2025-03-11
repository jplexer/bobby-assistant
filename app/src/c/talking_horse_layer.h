/*
 * Copyright 2025 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TALKING_HORSE_LAYER_H
#define TALKING_HORSE_LAYER_H

#include <pebble.h>

typedef Layer TalkingHorseLayer;

TalkingHorseLayer *talking_horse_layer_create(GRect frame);
void talking_horse_layer_destroy(TalkingHorseLayer *layer);
void talking_horse_layer_set_text(TalkingHorseLayer *layer, const char *text);

#endif //TALKING_HORSE_LAYER_H
