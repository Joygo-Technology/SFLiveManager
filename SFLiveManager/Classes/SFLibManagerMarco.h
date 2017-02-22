//
//  SFLibManagerMarco.h
//  LiveManager
//
//  Created by 朱盛雄 on 16/8/3.
//  Copyright © 2016年 Sunniwell. All rights reserved.
//

#ifndef SFLibManagerMarco_h
#define SFLibManagerMarco_h

#define kDefaultRecordSampleRate 44100.0
#define kDefaultRecordChannel 1

#define kDefaultPlaySampleRate 16000.0
#define kDefaultPlayChannel 1

#define VOLUME_VOICE		100
#define VOLUME_ACCOMP		50

#define P_TYPE_SIZE 1
// play time change(when (change > one second)), arg0:curPosSec[0, 99999999), arg1:durSec[0, 99999999)
#define P_TYPE_TIME 2
// buffering, arg0:buf[0, 100] == 100 when buffer end, arg1:not used
#define P_TYPE_BUF 3
// play end, arg0:not used, arg1:not used
#define P_TYPE_EOF 4
// play error, arg0:not used, arg1:not used
#define P_TYPE_ERROR 5

#endif /* SFLibManagerMarco_h */
