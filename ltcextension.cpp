/* @mediagen - Fix Syntax error: Unterminated quoted string -
 *
 * ltcextension.cpp
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

#include "stdafx.h"
#include <TBitstream.h>
#include "ltcextension.h"


__ALX_BEGIN_NAMESPACE

int wmt_timecode::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    wRange = var_bs.little_getbits(16);
    dwTimecode = var_bs.little_getbits(32);
    dwUserbits = var_bs.little_getbits(32);
    dwAmFlags = var_bs.little_getbits(32);
    return var_ret;
}

int wmt_timecode::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.little_putbits(wRange, 16);
    var_bs.little_putbits(dwTimecode, 32);
    var_bs.little_putbits(dwUserbits, 32);
    var_bs.little_putbits(dwAmFlags, 32);
    return var_ret;
}

int timecode_head::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    avg_frame_rate = var_bs.little_getbits(32);
    return var_ret;
}

int timecode_head::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.little_putbits(avg_frame_rate, 32);
    return var_ret;
}

__ALX_END_NAMESPACE
