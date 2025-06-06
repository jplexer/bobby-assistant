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

#include "root_window.h"
#include "consent/consent.h"
#include "converse/session_window.h"
#include "converse/conversation_manager.h"
#include "alarms/manager.h"
#include "version/version.h"
#include "settings/settings.h"

#include <pebble.h>
#include <pebble-events/pebble-events.h>

#define QUICK_LAUNCH_TIMEOUT_MS 60000

static RootWindow* s_root_window = NULL;

static void prv_init(void) {
  version_init();
  consent_migrate();
  settings_init();
  conversation_manager_init();
  events_app_message_open();
  alarm_manager_init();
}

static void prv_deinit(void) {
  if (s_root_window) {
    root_window_destroy(s_root_window);
  }
}

int main(void) {
  VersionInfo version_info = version_get_current();
  APP_LOG(APP_LOG_LEVEL_INFO, "Bobby %d.%d", version_info.major, version_info.minor);
  prv_init();
  
  if (alarm_manager_maybe_alarm()) {
    // don't actually have anything to do here - the alarm manager already did it.
  } else {
    if (must_present_consent()) {
      consent_window_push();
    } else {
      if (launch_reason() == APP_LAUNCH_QUICK_LAUNCH) {
        QuickLaunchBehaviour quick_launch_behaviour = settings_get_quick_launch_behaviour();
        if (quick_launch_behaviour != QuickLaunchBehaviourHomeScreen) {
          session_window_push(quick_launch_behaviour == QuickLaunchBehaviourConverseWithTimeout ? QUICK_LAUNCH_TIMEOUT_MS : 0, NULL);
        } else {
          s_root_window = root_window_create();
          root_window_push(s_root_window);
        }
      } else {
        s_root_window = root_window_create();
        root_window_push(s_root_window);
      }
    }
  }


  app_event_loop();
  prv_deinit();
}
