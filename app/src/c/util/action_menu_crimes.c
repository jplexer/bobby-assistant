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

#include "action_menu_crimes.h"
#include <pebble.h>

typedef struct {
  char padding[12];
  unsigned separator_index;
} ActionMenuLevelHack;

void action_menu_level_set_separator_index(ActionMenuLevel *level, unsigned index) {
  ActionMenuLevelHack *hack = (ActionMenuLevelHack *)level;
  hack->separator_index = index;
}
