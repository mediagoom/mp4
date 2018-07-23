/* @mediagen - experiment appveyor linux and win 0.25 -
 *
 * ltcextension.h
 * 
 * This file was automatically generated
 * from the source file:
 *     'ltcextension.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#ifndef var_ltcextension_h_
#define var_ltcextension_h_

// initial size of parsable arrays: 64


#include "mp4.h"


__ALX_BEGIN_NAMESPACE



// {8FF9D4A6-3160-4cf9-A29C-8C763FE62E03}


#define SET_LTC_BOX_Y(box, y) {int i = 0; unsigned char * bytes = box.direct_guid(); bytes[i++] = y;bytes[i++] = 0xf9;bytes[i++] = 0xd4;bytes[i++] = 0xa6;bytes[i++] = 0x31;bytes[i++] = 0x60;bytes[i++] = 0x4c;bytes[i++] = 0xf9;bytes[i++] = 0xa2;bytes[i++] = 0x9c;bytes[i++] = 0x8c;bytes[i++] = 0x76;bytes[i++] = 0x3f;bytes[i++] = 0xe6;bytes[i++] = 0x03;}
inline bool IS_LTC_BOX_Y(Box box, BYTE y) {int i = 0; const unsigned char * bytes = box.guid();  if(bytes[i++] != y) return false; if(bytes[i++] != 0xf9) return false; if(bytes[i++] != 0xd4) return false; if(bytes[i++] != 0xa6) return false; if(bytes[i++] != 0x31) return false; if(bytes[i++] != 0x60) return false; if(bytes[i++] != 0x4c) return false; if(bytes[i++] != 0xf9) return false; if(bytes[i++] != 0xa2) return false; if(bytes[i++] != 0x9c) return false; if(bytes[i++] != 0x8c) return false; if(bytes[i++] != 0x76) return false; if(bytes[i++] != 0x3f) return false; if(bytes[i++] != 0xe6) return false; if(bytes[i++] != 0x03) return false; return true;}

#define SET_LTC_BOX(box) SET_LTC_BOX_Y(box, 0x8f)
#define IS_LTC_BOX(box) IS_LTC_BOX_Y(box, 0x8f)

#define SET_LTC_HANDLER(box) SET_LTC_BOX_Y(box, 0xef)
#define IS_LTC_HANDLER(box) IS_LTC_BOX_Y(box, 0xef)

#define TIMECODE_READ 0x664
#define TIMECODE_READ_INTERPOLATED 0x665
#define TIMECODE_EXP_ELLAPSED 0x666
#define TIMECODE_EXP_INTERPOLATED 0x667

#define TIMECODE_MISSING 0xFFFF
#define TIMECODE_MISSING_VALUE 0xFFFFFFFF



class wmt_timecode {
public:
    unsigned short int wRange;
    unsigned int dwTimecode;
    unsigned int dwUserbits;
    unsigned int dwAmFlags;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class timecode_head {
public:
    unsigned int avg_frame_rate;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_ltcextension_h_ */
