/* @mediagen - working on multibitrate test -
 *
 * mp4.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'mp4.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "mp4.h"


__ALX_BEGIN_NAMESPACE
const unsigned int BOX_UUID = 1970628964;
const unsigned int handler_vide = 1986618469;
const unsigned int handler_soun = 1936684398;

int Box::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    size = var_bs.getbits(32);
    type = var_bs.getbits(32);
    if (size==1)
    {
        x = var_bs.getbits(32);
        y = var_bs.getbits(32);
    }
    
    if (type==1970628964)
    {
        byte_01 = var_bs.getbits(8);
        byte_02 = var_bs.getbits(8);
        byte_03 = var_bs.getbits(8);
        byte_04 = var_bs.getbits(8);
        byte_05 = var_bs.getbits(8);
        byte_06 = var_bs.getbits(8);
        byte_07 = var_bs.getbits(8);
        byte_08 = var_bs.getbits(8);
        byte_09 = var_bs.getbits(8);
        byte_10 = var_bs.getbits(8);
        byte_11 = var_bs.getbits(8);
        byte_12 = var_bs.getbits(8);
        byte_13 = var_bs.getbits(8);
        byte_14 = var_bs.getbits(8);
        byte_15 = var_bs.getbits(8);
        byte_16 = var_bs.getbits(8);
    }
    
    
         I2C(type, _stype);
   
    return var_ret;
}

int Box::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(size, 32);
    var_bs.putbits(type, 32);
    if (size==1)
    {
        var_bs.putbits(x, 32);
        var_bs.putbits(y, 32);
    }
    
    if (type==1970628964)
    {
        var_bs.putbits(byte_01, 8);
        var_bs.putbits(byte_02, 8);
        var_bs.putbits(byte_03, 8);
        var_bs.putbits(byte_04, 8);
        var_bs.putbits(byte_05, 8);
        var_bs.putbits(byte_06, 8);
        var_bs.putbits(byte_07, 8);
        var_bs.putbits(byte_08, 8);
        var_bs.putbits(byte_09, 8);
        var_bs.putbits(byte_10, 8);
        var_bs.putbits(byte_11, 8);
        var_bs.putbits(byte_12, 8);
        var_bs.putbits(byte_13, 8);
        var_bs.putbits(byte_14, 8);
        var_bs.putbits(byte_15, 8);
        var_bs.putbits(byte_16, 8);
    }
    
    return var_ret;
}

int FullBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    version = var_bs.getbits(8);
    flags = var_bs.getbits(24);
    return var_ret;
}

int FullBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.putbits(version, 8);
    var_bs.putbits(flags, 24);
    return var_ret;
}

int PixelAspectRatioBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    hSpacing = var_bs.getbits(32);
    vSpacing = var_bs.getbits(32);
    return var_ret;
}

int PixelAspectRatioBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(hSpacing, 32);
    var_bs.putbits(vSpacing, 32);
    return var_ret;
}

int CleanApertureBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    cleanApertureWidthN = var_bs.getbits(32);
    cleanApertureWidthD = var_bs.getbits(32);
    cleanApertureHeightN = var_bs.getbits(32);
    cleanApertureHeightD = var_bs.getbits(32);
    horizOffN = var_bs.getbits(32);
    horizOffD = var_bs.getbits(32);
    vertOffN = var_bs.getbits(32);
    vertOffD = var_bs.getbits(32);
    return var_ret;
}

int CleanApertureBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(cleanApertureWidthN, 32);
    var_bs.putbits(cleanApertureWidthD, 32);
    var_bs.putbits(cleanApertureHeightN, 32);
    var_bs.putbits(cleanApertureHeightD, 32);
    var_bs.putbits(horizOffN, 32);
    var_bs.putbits(horizOffD, 32);
    var_bs.putbits(vertOffN, 32);
    var_bs.putbits(vertOffD, 32);
    return var_ret;
}

int MovieHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (version==1)
    {
        creation_time_0 = var_bs.getbits(32);
        creation_time = var_bs.getbits(32);
        modification_time_0 = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        timescale = var_bs.getbits(32);
        duration_0 = var_bs.getbits(32);
        duration = var_bs.getbits(32);
    }
    else
    {
        creation_time = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        timescale = var_bs.getbits(32);
        duration = var_bs.getbits(32);
    }
    
    rate = var_bs.sgetbits(32);
    volume = var_bs.sgetbits(16);
    bit_reserved = var_bs.getbits(16);
    if (bit_reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'bit_reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    matrix_1 = var_bs.sgetbits(32);
    matrix_2 = var_bs.sgetbits(32);
    matrix_3 = var_bs.sgetbits(32);
    matrix_4 = var_bs.sgetbits(32);
    matrix_5 = var_bs.sgetbits(32);
    matrix_6 = var_bs.sgetbits(32);
    matrix_7 = var_bs.sgetbits(32);
    matrix_8 = var_bs.sgetbits(32);
    matrix_9 = var_bs.sgetbits(32);
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    next_track_ID = var_bs.getbits(32);
    return var_ret;
}

int MovieHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (version==1)
    {
        var_bs.putbits(creation_time_0, 32);
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time_0, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(timescale, 32);
        var_bs.putbits(duration_0, 32);
        var_bs.putbits(duration, 32);
    }
    else
    {
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(timescale, 32);
        var_bs.putbits(duration, 32);
    }
    
    var_bs.putbits(rate, 32);
    var_bs.putbits(volume, 16);
    var_parse = 16;
    bit_reserved = 0;
    var_bs.putbits(bit_reserved, var_parse);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(matrix_1, 32);
    var_bs.putbits(matrix_2, 32);
    var_bs.putbits(matrix_3, 32);
    var_bs.putbits(matrix_4, 32);
    var_bs.putbits(matrix_5, 32);
    var_bs.putbits(matrix_6, 32);
    var_bs.putbits(matrix_7, 32);
    var_bs.putbits(matrix_8, 32);
    var_bs.putbits(matrix_9, 32);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_bs.putbits(next_track_ID, 32);
    return var_ret;
}

int TrackHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (version==1)
    {
        creation_time_0 = var_bs.getbits(32);
        creation_time = var_bs.getbits(32);
        modification_time_0 = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        track_ID = var_bs.getbits(32);
        reserved = var_bs.getbits(32);
        if (reserved != 0) {
            MG_ERROR(_T("Const value mismatch for 'reserved'"));
            var_ret++;
        }
        duration_0 = var_bs.getbits(32);
        duration = var_bs.getbits(32);
    }
    else
    {
        creation_time = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        track_ID = var_bs.getbits(32);
        reserved = var_bs.getbits(32);
        if (reserved != 0) {
            MG_ERROR(_T("Const value mismatch for 'reserved'"));
            var_ret++;
        }
        duration = var_bs.getbits(32);
    }
    
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    layer = var_bs.sgetbits(16);
    alternate_group = var_bs.sgetbits(16);
    volume = var_bs.sgetbits(16);
    reserved = var_bs.getbits(16);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    matrix_1 = var_bs.sgetbits(32);
    matrix_2 = var_bs.sgetbits(32);
    matrix_3 = var_bs.sgetbits(32);
    matrix_4 = var_bs.sgetbits(32);
    matrix_5 = var_bs.sgetbits(32);
    matrix_6 = var_bs.sgetbits(32);
    matrix_7 = var_bs.sgetbits(32);
    matrix_8 = var_bs.sgetbits(32);
    matrix_9 = var_bs.sgetbits(32);
    width = var_bs.getbits(16);
    width_coma = var_bs.getbits(16);
    height = var_bs.getbits(16);
    height_coma = var_bs.getbits(16);
    return var_ret;
}

int TrackHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (version==1)
    {
        var_bs.putbits(creation_time_0, 32);
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time_0, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(track_ID, 32);
        var_parse = 32;
        reserved = 0;
        var_bs.putbits(reserved, var_parse);
        var_bs.putbits(duration_0, 32);
        var_bs.putbits(duration, 32);
    }
    else
    {
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(track_ID, 32);
        var_parse = 32;
        reserved = 0;
        var_bs.putbits(reserved, var_parse);
        var_bs.putbits(duration, 32);
    }
    
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(layer, 16);
    var_bs.putbits(alternate_group, 16);
    var_bs.putbits(volume, 16);
    var_parse = 16;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(matrix_1, 32);
    var_bs.putbits(matrix_2, 32);
    var_bs.putbits(matrix_3, 32);
    var_bs.putbits(matrix_4, 32);
    var_bs.putbits(matrix_5, 32);
    var_bs.putbits(matrix_6, 32);
    var_bs.putbits(matrix_7, 32);
    var_bs.putbits(matrix_8, 32);
    var_bs.putbits(matrix_9, 32);
    var_bs.putbits(width, 16);
    var_bs.putbits(width_coma, 16);
    var_bs.putbits(height, 16);
    var_bs.putbits(height_coma, 16);
    return var_ret;
}

int MediaHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (version==1)
    {
        creation_time_0 = var_bs.getbits(32);
        creation_time = var_bs.getbits(32);
        modification_time_0 = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        timescale = var_bs.getbits(32);
        duration_0 = var_bs.getbits(32);
        duration = var_bs.getbits(32);
    }
    else
    {
        creation_time = var_bs.getbits(32);
        modification_time = var_bs.getbits(32);
        timescale = var_bs.getbits(32);
        duration = var_bs.getbits(32);
    }
    
    pad = var_bs.getbits(1);
    if (pad != 0) {
        MG_ERROR(_T("Const value mismatch for 'pad'"));
        var_ret++;
    }
    lang_1 = var_bs.getbits(5);
    lang_2 = var_bs.getbits(5);
    lang_3 = var_bs.getbits(5);
    pre_defined = var_bs.getbits(16);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    return var_ret;
}

int MediaHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (version==1)
    {
        var_bs.putbits(creation_time_0, 32);
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time_0, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(timescale, 32);
        var_bs.putbits(duration_0, 32);
        var_bs.putbits(duration, 32);
    }
    else
    {
        var_bs.putbits(creation_time, 32);
        var_bs.putbits(modification_time, 32);
        var_bs.putbits(timescale, 32);
        var_bs.putbits(duration, 32);
    }
    
    var_parse = 1;
    pad = 0;
    var_bs.putbits(pad, var_parse);
    var_bs.putbits(lang_1, 5);
    var_bs.putbits(lang_2, 5);
    var_bs.putbits(lang_3, 5);
    var_parse = 16;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    return var_ret;
}

int HandlerBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    handler_type = var_bs.getbits(32);
    reserved = var_bs.getbits(32);
    reserved = var_bs.getbits(32);
    reserved = var_bs.getbits(32);
    __x = 0;
    __max = 0;
    __max = __body_size;
    while (__x<__max) {
        __name = var_bs.sgetbits(8);
        
       _ASSERTE(__max < 1022);

      desc[__x++] = __name;
      //if(__name == '\0')
      //	 break;
      
    }
    
    desc[__x] = '\0';
    I2C(handler_type, htype);
    
    return var_ret;
}

int HandlerBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_bs.putbits(handler_type, 32);
    var_bs.putbits(reserved, 32);
    var_bs.putbits(reserved, 32);
    var_bs.putbits(reserved, 32);
    __x = 0;
    __max = 0;
    __max = __body_size;
    while (__x<__max) {
        __name = desc[__x++];
        var_bs.putbits(__name, 8);
    }
    return var_ret;
}

int DataReferenceBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    entry_count = var_bs.getbits(32);
    return var_ret;
}

int DataReferenceBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(entry_count, 32);
    return var_ret;
}

int SampleDescriptionBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    entry_count = var_bs.getbits(32);
    return var_ret;
}

int SampleDescriptionBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(entry_count, 32);
    return var_ret;
}

int SampleEntry::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    data_reference_index = var_bs.sgetbits(16);
    return var_ret;
}

int SampleEntry::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(data_reference_index, 16);
    return var_ret;
}

int VisualSampleEntry::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += SampleEntry::get(var_bs);
    pre_defined = var_bs.getbits(16);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    reserved = var_bs.getbits(16);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    pre_defined = var_bs.getbits(32);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    width = var_bs.getbits(16);
    height = var_bs.getbits(16);
    horizresolution = var_bs.getbits(32);
    vertresolution = var_bs.getbits(32);
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    frame_count = var_bs.getbits(16);
    size = var_bs.getbits(8);
    idx = 0;
    _string_array_size = 31;
    while (idx<size) {
        var_dim0 = idx++;
        compressorname[var_dim0] = var_bs.sgetbits(8);
    }
    compressorname[idx++] = '\0';_string_array_size++;
    while (idx<_string_array_size) {
        var_dim0 = idx++;
        compressorname[var_dim0] = var_bs.sgetbits(8);
    }
    depth = var_bs.getbits(16);
    pre_defined16 = var_bs.sgetbits(16);
    if (pre_defined16 != -1) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined16'"));
        var_ret++;
    }
    return var_ret;
}

int VisualSampleEntry::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += SampleEntry::put(var_bs);
    var_parse = 16;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 16;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 32;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_bs.putbits(width, 16);
    var_bs.putbits(height, 16);
    var_bs.putbits(horizresolution, 32);
    var_bs.putbits(vertresolution, 32);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(frame_count, 16);
    var_bs.putbits(size, 8);
    idx = 0;
    _string_array_size = 31;
    while (idx<size) {
        var_dim0 = idx++;
        var_bs.putbits(compressorname[var_dim0], 8);
    }
    while (idx<_string_array_size) {
        var_dim0 = idx++;
        var_bs.putbits(compressorname[var_dim0], 8);
    }
    var_bs.putbits(depth, 16);
    var_parse = 16;
    pre_defined16 = -1;
    var_bs.putbits(pre_defined16, var_parse);
    return var_ret;
}

int AVCDecoderConfigurationRecord::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    configurationVersion = var_bs.getbits(8);
    if (configurationVersion != 1) {
        MG_ERROR(_T("Const value mismatch for 'configurationVersion'"));
        var_ret++;
    }
    AVCProfileIndication = var_bs.getbits(8);
    profile_compatibility = var_bs.getbits(8);
    AVCLevelIndication = var_bs.getbits(8);
    reserved = var_bs.getbits(6);
    if (reserved != 63) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    lengthSizeMinusOne = var_bs.getbits(2);
    reserved = var_bs.getbits(3);
    if(0x7 != reserved){MG_WARNING("AVCDecoderConfigurationRecord reserved mismatch!");}
    numOfSequenceParameterSets = var_bs.getbits(5);
    __idx = 0;
    __idy = 0;
    for (__idx=0; __idx<numOfSequenceParameterSets; __idx++) {
        var_dim0 = __idx;
        sequenceParameterSetLength[var_dim0] = var_bs.getbits(16);
        for (__idy=0; __idy<sequenceParameterSetLength[__idx]; __idy++) {
            var_dim0 = __idy;
            sequenceParameterSetNALUnit[var_dim0] = var_bs.getbits(8);
        }
        add_sequence_parameter_set(sequenceParameterSetNALUnit, sequenceParameterSetLength[__idx]);
    }
    numOfPictureParameterSets = var_bs.getbits(8);
    for (__idx=0; __idx<numOfPictureParameterSets; __idx++) {
        var_dim0 = __idx;
        pictureParameterSetLength[var_dim0] = var_bs.getbits(16);
        for (__idy=0; __idy<pictureParameterSetLength[__idx]; __idy++) {
            var_dim0 = __idy;
            pictureParameterSetNALUnit[var_dim0] = var_bs.getbits(8);
        }
        add_picture_parameter_set(pictureParameterSetNALUnit, pictureParameterSetLength[__idx]);
    }
    return var_ret;
}

int AVCDecoderConfigurationRecord::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    int var_parse = 0;
    var_bs.align(8);
    var_parse = 8;
    configurationVersion = 1;
    var_bs.putbits(configurationVersion, var_parse);
    var_bs.putbits(AVCProfileIndication, 8);
    var_bs.putbits(profile_compatibility, 8);
    var_bs.putbits(AVCLevelIndication, 8);
    var_parse = 6;
    reserved = 63;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(lengthSizeMinusOne, 2);
    reserved = 0x7;
    var_bs.putbits(reserved, 3);
    var_bs.putbits(numOfSequenceParameterSets, 5);
    __idx = 0;
    __idy = 0;
    for (__idx=0; __idx<numOfSequenceParameterSets; __idx++) {
        var_dim0 = __idx;
        var_bs.putbits(sequenceParameterSetLength[var_dim0], 16);
        for (__idy=0; __idy<sequenceParameterSetLength[__idx]; __idy++) {
            var_dim0 = __idy;
            var_bs.putbits(sequenceParameterSetNALUnit[var_dim0], 8);
        }
    }
    var_bs.putbits(numOfPictureParameterSets, 8);
    for (__idx=0; __idx<numOfPictureParameterSets; __idx++) {
        var_dim0 = __idx;
        var_bs.putbits(pictureParameterSetLength[var_dim0], 16);
        for (__idy=0; __idy<pictureParameterSetLength[__idx]; __idy++) {
            var_dim0 = __idy;
            var_bs.putbits(pictureParameterSetNALUnit[var_dim0], 8);
        }
    }
    return var_ret;
}

int BitRateBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    bufferSizeDB = var_bs.getbits(32);
    maxBitrate = var_bs.getbits(32);
    avgBitrate = var_bs.getbits(32);
    return var_ret;
}

int BitRateBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(bufferSizeDB, 32);
    var_bs.putbits(maxBitrate, 32);
    var_bs.putbits(avgBitrate, 32);
    return var_ret;
}

int TimeToSampleBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    entry_count = var_bs.getbits(32);
    return var_ret;
}

int TimeToSampleBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(entry_count, 32);
    return var_ret;
}

int AudioSampleEntry::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += SampleEntry::get(var_bs);
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reserved = var_bs.getbits(32);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    channelcount = var_bs.getbits(16);
    samplesize = var_bs.getbits(16);
    pre_defined = var_bs.getbits(16);
    if (pre_defined != 0) {
        MG_ERROR(_T("Const value mismatch for 'pre_defined'"));
        var_ret++;
    }
    reserved16 = var_bs.getbits(16);
    if (reserved16 != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved16'"));
        var_ret++;
    }
    samplerate = var_bs.getbits(32);
    return var_ret;
}

int AudioSampleEntry::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += SampleEntry::put(var_bs);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 32;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(channelcount, 16);
    var_bs.putbits(samplesize, 16);
    var_parse = 16;
    pre_defined = 0;
    var_bs.putbits(pre_defined, var_parse);
    var_parse = 16;
    reserved16 = 0;
    var_bs.putbits(reserved16, var_parse);
    var_bs.putbits(samplerate, 32);
    return var_ret;
}

int EditListBoxItem::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    return var_ret;
}

int EditListBoxItem::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    return var_ret;
}

int EditListBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    __entry_count = var_bs.getbits(32);
    __i = 0;
    for (__i=1; __i<=__entry_count; __i++) {
        if (version==1)
        {
            segment_duration_0 = var_bs.getbits(32);
            segment_duration = var_bs.getbits(32);
            media_time_0 = var_bs.sgetbits(32);
            media_time = var_bs.sgetbits(32);
        }
        else
        {
            segment_duration = var_bs.getbits(32);
            media_time = var_bs.sgetbits(32);
        }
        
        media_rate_integer = var_bs.sgetbits(16);
        media_rate_fraction = var_bs.sgetbits(16);
        if (media_rate_fraction != 0) {
            MG_ERROR(_T("Const value mismatch for 'media_rate_fraction'"));
            var_ret++;
        }
        
		add_item(get_segment_duration()
		       , get_media_time()
		       , media_rate_integer
		       , media_rate_fraction);

		
    }
    return var_ret;
}

int EditListBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
     
	_ASSERTE(_items.size());
	__entry_count = (ST_U32(_items.size()));
	
    var_bs.putbits(__entry_count, 32);
    __i = 0;
    for (__i=1; __i<=__entry_count; __i++) {
        
		    _ASSERTE(__i <= _items.size());

		    set_segment_duration(_items[__i - 1]->_segment_duration);
		    set_media_time(_items[__i - 1]->_media_time);
		    media_rate_integer  = _items[__i - 1]->_media_rate_integer;
		    media_rate_fraction = _items[__i - 1]->_media_rate_fraction;
		   
		
        if (version==1)
        {
            var_bs.putbits(segment_duration_0, 32);
            var_bs.putbits(segment_duration, 32);
            var_bs.putbits(media_time_0, 32);
            var_bs.putbits(media_time, 32);
        }
        else
        {
            var_bs.putbits(segment_duration, 32);
            var_bs.putbits(media_time, 32);
        }
        
        var_bs.putbits(media_rate_integer, 16);
        var_parse = 16;
        media_rate_fraction = 0;
        var_bs.putbits(media_rate_fraction, var_parse);
    }
    return var_ret;
}

int FileTypeBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    major_brand = var_bs.getbits(32);
    minor_version = var_bs.getbits(32);
    __size = 0;
    __size = _size;
    while (__size>0) {
        compatible_brand = var_bs.getbits(32);
        __size-=4;
        _items.push_back(compatible_brand);
    }
    return var_ret;
}

int FileTypeBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(major_brand, 32);
    var_bs.putbits(minor_version, 32);
    __size = 0;
    __size = ST_U32(_items.size() * 4);int c = 0;
    while (__size>0) {
        compatible_brand = _items[c++];
        var_bs.putbits(compatible_brand, 32);
        __size-=4;
    }
    return var_ret;
}

int SoundMediaHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    balance = var_bs.sgetbits(16);
    reserved = var_bs.getbits(16);
    return var_ret;
}

int SoundMediaHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(balance, 16);
    var_bs.putbits(reserved, 16);
    return var_ret;
}

int VideoMediaHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    graphicsmode = var_bs.getbits(16);
    opcolor1 = var_bs.getbits(16);
    opcolor2 = var_bs.getbits(16);
    opcolor3 = var_bs.getbits(16);
    return var_ret;
}

int VideoMediaHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(graphicsmode, 16);
    var_bs.putbits(opcolor1, 16);
    var_bs.putbits(opcolor2, 16);
    var_bs.putbits(opcolor3, 16);
    return var_ret;
}

int SegmentIndexBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    reference_ID = var_bs.getbits(32);
    timescale = var_bs.getbits(32);
    if (version==0)
    {
        earliest_presentation_time = var_bs.getbits(32);
        first_offset = var_bs.getbits(32);
    }
    else
    {
        earliest_presentation_time_0 = var_bs.getbits(32);
        earliest_presentation_time = var_bs.getbits(32);
        first_offset_0 = var_bs.getbits(32);
        first_offset = var_bs.getbits(32);
    }
    
    reserved = var_bs.getbits(16);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    reference_count = var_bs.getbits(16);
    i = 0;
    
	 _ASSERTE(reference_count <= sizeof(reference_type));
	 
    for (i=0; i<reference_count; i++) {
        var_dim0 = i;
        reference_type[var_dim0] = var_bs.getbits(1);
        var_dim0 = i;
        referenced_size[var_dim0] = var_bs.getbits(31);
        var_dim0 = i;
        subsegment_duration[var_dim0] = var_bs.getbits(32);
        var_dim0 = i;
        starts_with_SAP[var_dim0] = var_bs.getbits(1);
        var_dim0 = i;
        SAP_type[var_dim0] = var_bs.getbits(3);
        var_dim0 = i;
        SAP_delta_time[var_dim0] = var_bs.getbits(28);
    }
    return var_ret;
}

int SegmentIndexBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(reference_ID, 32);
    var_bs.putbits(timescale, 32);
    if (version==0)
    {
        var_bs.putbits(earliest_presentation_time, 32);
        var_bs.putbits(first_offset, 32);
    }
    else
    {
        var_bs.putbits(earliest_presentation_time_0, 32);
        var_bs.putbits(earliest_presentation_time, 32);
        var_bs.putbits(first_offset_0, 32);
        var_bs.putbits(first_offset, 32);
    }
    
    var_parse = 16;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(reference_count, 16);
    i = 0;
    for (i=0; i<reference_count; i++) {
        var_dim0 = i;
        var_bs.putbits(reference_type[var_dim0], 1);
        var_dim0 = i;
        var_bs.putbits(referenced_size[var_dim0], 31);
        var_dim0 = i;
        var_bs.putbits(subsegment_duration[var_dim0], 32);
        var_dim0 = i;
        var_bs.putbits(starts_with_SAP[var_dim0], 1);
        var_dim0 = i;
        var_bs.putbits(SAP_type[var_dim0], 3);
        var_dim0 = i;
        var_bs.putbits(SAP_delta_time[var_dim0], 28);
    }
    return var_ret;
}

int XmlBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    __x = 0;
    __max = 0;
    __max = ST_U32(__body_size);
    while (__x<__max) {
        __name = var_bs.sgetbits(8);
        _p_xml[__x++] = __name;
    }
    
       _p_xml[__x] = '\0';
    
    return var_ret;
}

int XmlBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    __x = 0;
    __max = 0;
    __max = ST_U32(__body_size);
    while (__x<__max) {
        __name = _p_xml[__x++];
        var_bs.putbits(__name, 8);
    }
    return var_ret;
}

__ALX_END_NAMESPACE
