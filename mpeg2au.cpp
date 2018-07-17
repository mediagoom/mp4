/* @mediagen - fixing hashes and replaces between win and nx -
 *
 * mpeg2au.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'mpeg2au.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "mpeg2au.h"


__ALX_BEGIN_NAMESPACE
const unsigned int LAYER1 = 3;
const unsigned int LAYER2 = 2;
const unsigned int LAYER3 = 1;
const int SINGLE_CHANNEL = 3;
const int DUAL_CHANNEL = 2;
const int JOINT_STEREO = 1;
const int STEREO = 0;
const int BITRATE[4][4][16] = { { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 0 }, { 0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 0 }, { 0, 32, 48, 56, 64, 80, 96, 112, 128, 144, 160, 176, 192, 224, 256, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 0 }, { 0, 8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 144, 160, 0 }, { 0, 32, 48, 56, 64, 80, 96, 112, 128, 144, 160, 176, 192, 224, 256, 0 } }, { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 0 }, { 0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, 0 }, { 0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 0 } } };
const int SAMPLING_FREQ[4][4] = { { 11025, 12000, 8000, -1 }, { -1, -1, -1, -1 }, { 22050, 24000, 16000, -1 }, { 44100, 48000, 32000, -1 } };
const int COEFFICIENTS[2][3] = { { 12, 144, 144 }, { 12, 144, 72 } };

int AudioHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    syncword = var_bs.getbits(11);
    if (syncword != 2047) {
        MG_ERROR(_T("Const value mismatch for 'syncword'"));
        var_ret++;
    }
    id = var_bs.getbits(2);
    layer = var_bs.getbits(2);
    protection_bit = var_bs.getbits(1);
    bitrate_index = var_bs.getbits(4);
    sampling_frequency = var_bs.getbits(2);
    padding_bit = var_bs.getbits(1);
    private_bit = var_bs.getbits(1);
    mode = var_bs.getbits(2);
    mode_extension = var_bs.getbits(2);
    copyright = var_bs.getbits(1);
    original_copy = var_bs.getbits(1);
    emphasis = var_bs.getbits(2);
    return var_ret;
}

int AudioHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 11;
    syncword = 2047;
    var_bs.putbits(syncword, var_parse);
    var_bs.putbits(id, 2);
    var_bs.putbits(layer, 2);
    var_bs.putbits(protection_bit, 1);
    var_bs.putbits(bitrate_index, 4);
    var_bs.putbits(sampling_frequency, 2);
    var_bs.putbits(padding_bit, 1);
    var_bs.putbits(private_bit, 1);
    var_bs.putbits(mode, 2);
    var_bs.putbits(mode_extension, 2);
    var_bs.putbits(copyright, 1);
    var_bs.putbits(original_copy, 1);
    var_bs.putbits(emphasis, 2);
    return var_ret;
}

int ID3::get(IBitstream &var_bs) {
    int var_ret = 0;
    ID_1 = var_bs.getbits(8);
    ID_2 = var_bs.getbits(8);
    ID_3 = var_bs.getbits(8);
    return var_ret;
}

int ID3::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.putbits(ID_1, 8);
    var_bs.putbits(ID_2, 8);
    var_bs.putbits(ID_3, 8);
    return var_ret;
}

int ID2V2_3::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += ID3::get(var_bs);
    Version = var_bs.getbits(8);
    Revision = var_bs.getbits(8);
    Flags = var_bs.getbits(5);
    if (Flags != 0) {
        MG_ERROR(_T("Const value mismatch for 'Flags'"));
        var_ret++;
    }
    ExperimentalIndicator = var_bs.getbits(1);
    Extendedheader = var_bs.getbits(1);
    Unsynchronisation = var_bs.getbits(1);
    check = var_bs.getbits(1);
    if (check != 0) {
        MG_ERROR(_T("Const value mismatch for 'check'"));
        var_ret++;
    }
    size1 = var_bs.getbits(7);
    check = var_bs.getbits(1);
    if (check != 0) {
        MG_ERROR(_T("Const value mismatch for 'check'"));
        var_ret++;
    }
    size2 = var_bs.getbits(7);
    check = var_bs.getbits(1);
    if (check != 0) {
        MG_ERROR(_T("Const value mismatch for 'check'"));
        var_ret++;
    }
    size3 = var_bs.getbits(7);
    check = var_bs.getbits(1);
    if (check != 0) {
        MG_ERROR(_T("Const value mismatch for 'check'"));
        var_ret++;
    }
    size4 = var_bs.getbits(7);
    Size = ((size1<<21)|(size2<<14)|(size3<<7)|(size4))+10;
    return var_ret;
}

int ID2V2_3::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_ret += ID3::put(var_bs);
    var_bs.putbits(Version, 8);
    var_bs.putbits(Revision, 8);
    var_parse = 5;
    Flags = 0;
    var_bs.putbits(Flags, var_parse);
    var_bs.putbits(ExperimentalIndicator, 1);
    var_bs.putbits(Extendedheader, 1);
    var_bs.putbits(Unsynchronisation, 1);
    var_parse = 1;
    check = 0;
    var_bs.putbits(check, var_parse);
    var_bs.putbits(size1, 7);
    var_parse = 1;
    check = 0;
    var_bs.putbits(check, var_parse);
    var_bs.putbits(size2, 7);
    var_parse = 1;
    check = 0;
    var_bs.putbits(check, var_parse);
    var_bs.putbits(size3, 7);
    var_parse = 1;
    check = 0;
    var_bs.putbits(check, var_parse);
    var_bs.putbits(size4, 7);
    Size = ((size1<<21)|(size2<<14)|(size3<<7)|(size4))+10;
    return var_ret;
}

__ALX_END_NAMESPACE
