/*
 * Copyright 2020 Rockchip Electronics Co. LTD
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
 *
 */
#ifndef SRC_INCLUDE_UAC_CONTROL_GRAPH_H_
#define SRC_INCLUDE_UAC_CONTROL_GRAPH_H_

#include "uac_control.h"

class UACControlGraph : public UACControl {
 public:
    UACControlGraph();
    virtual ~UACControlGraph();

 public:
    virtual int uacStart(int type);
    virtual void uacStop(int type);
    virtual void uacSetSampleRate(int type, int sampleRate);
    virtual void uacSetVolume(int type, int volume);
    virtual void uacSetMute(int type, int mute);
    virtual void uacSetPpm(int type, int ppm);

 private:
    void *mCtx;
};

#endif  // SRC_INCLUDE_UAC_CONTROL_GRAPH_H_