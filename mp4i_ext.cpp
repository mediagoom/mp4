/* @mediagen - experiment appveyor linux and win 0.29 -
 *
 * mp4i_ext.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'mp4i_ext.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "mp4i_ext.h"


__ALX_BEGIN_NAMESPACE

int ilst_box::get(IBitstream &var_bs) {
    int var_ret = 0;
    subtype = 0;
    return var_ret;
}

int ilst_box::put(IBitstream &var_bs) {
    int var_ret = 0;
    subtype = 0;
    return var_ret;
}

int data_box::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += FullBox::get(var_bs);
    reserved = var_bs.getbits(32);
    return var_ret;
}

int data_box::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(reserved, 32);
    return var_ret;
}

__ALX_END_NAMESPACE
