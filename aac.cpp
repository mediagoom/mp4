/* @mediagen - experiment appveyor linux and win 0.19 -
 *
 * aac.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'aac.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "aac.h"


__ALX_BEGIN_NAMESPACE

int mpeg4audio_sample_rates::nextvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_hit = 1;

    var_data = var_bs.nextbits(4);
    switch (var_data) {
    case 0:
        *var_arg = 96000;
        var_size = 4;
        break;
    case 1:
        *var_arg = 88200;
        var_size = 4;
        break;
    case 2:
        *var_arg = 64000;
        var_size = 4;
        break;
    case 3:
        *var_arg = 48000;
        var_size = 4;
        break;
    case 4:
        *var_arg = 44100;
        var_size = 4;
        break;
    case 5:
        *var_arg = 32000;
        var_size = 4;
        break;
    case 6:
        *var_arg = 24000;
        var_size = 4;
        break;
    case 7:
        *var_arg = 22050;
        var_size = 4;
        break;
    case 8:
        *var_arg = 16000;
        var_size = 4;
        break;
    case 9:
        *var_arg = 12000;
        var_size = 4;
        break;
    case 10:
        *var_arg = 11025;
        var_size = 4;
        break;
    case 11:
        *var_arg = 8000;
        var_size = 4;
        break;
    case 12:
        *var_arg = 7350;
        var_size = 4;
        break;
    default:
        var_hit = 0;
    }
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int mpeg4audio_sample_rates::getvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_esc_bits = 0;
    int var_hit = 1;

    var_data = var_bs.nextbits(4);
    switch (var_data) {
    case 0:
        var_bs.skipbits(4);
        *var_arg = 96000;
        var_size = 4;
        break;
    case 1:
        var_bs.skipbits(4);
        *var_arg = 88200;
        var_size = 4;
        break;
    case 2:
        var_bs.skipbits(4);
        *var_arg = 64000;
        var_size = 4;
        break;
    case 3:
        var_bs.skipbits(4);
        *var_arg = 48000;
        var_size = 4;
        break;
    case 4:
        var_bs.skipbits(4);
        *var_arg = 44100;
        var_size = 4;
        break;
    case 5:
        var_bs.skipbits(4);
        *var_arg = 32000;
        var_size = 4;
        break;
    case 6:
        var_bs.skipbits(4);
        *var_arg = 24000;
        var_size = 4;
        break;
    case 7:
        var_bs.skipbits(4);
        *var_arg = 22050;
        var_size = 4;
        break;
    case 8:
        var_bs.skipbits(4);
        *var_arg = 16000;
        var_size = 4;
        break;
    case 9:
        var_bs.skipbits(4);
        *var_arg = 12000;
        var_size = 4;
        break;
    case 10:
        var_bs.skipbits(4);
        *var_arg = 11025;
        var_size = 4;
        break;
    case 11:
        var_bs.skipbits(4);
        *var_arg = 8000;
        var_size = 4;
        break;
    case 12:
        var_bs.skipbits(4);
        *var_arg = 7350;
        var_size = 4;
        break;
    default:
        var_hit = 0;
    }
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int mpeg4audio_sample_rates::putvlc(IBitstream &var_bs, unsigned int var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_esc_bits = 0;
    int var_hit = 1;

    if (var_arg == 96000) {
        var_bs.putbits(0,4);
        var_size = 4;
        var_data = 0;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 88200) {
        var_bs.putbits(1,4);
        var_size = 4;
        var_data = 1;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 64000) {
        var_bs.putbits(2,4);
        var_size = 4;
        var_data = 2;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 48000) {
        var_bs.putbits(3,4);
        var_size = 4;
        var_data = 3;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 44100) {
        var_bs.putbits(4,4);
        var_size = 4;
        var_data = 4;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 32000) {
        var_bs.putbits(5,4);
        var_size = 4;
        var_data = 5;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 24000) {
        var_bs.putbits(6,4);
        var_size = 4;
        var_data = 6;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 22050) {
        var_bs.putbits(7,4);
        var_size = 4;
        var_data = 7;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 16000) {
        var_bs.putbits(8,4);
        var_size = 4;
        var_data = 8;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 12000) {
        var_bs.putbits(9,4);
        var_size = 4;
        var_data = 9;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 11025) {
        var_bs.putbits(10,4);
        var_size = 4;
        var_data = 10;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 8000) {
        var_bs.putbits(11,4);
        var_size = 4;
        var_data = 11;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 7350) {
        var_bs.putbits(12,4);
        var_size = 4;
        var_data = 12;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    var_hit = 0;
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int mpeg4audio_channels::nextvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_hit = 1;

    var_data = var_bs.nextbits(3);
    switch (var_data) {
    case 0:
        *var_arg = 0;
        var_size = 3;
        break;
    case 1:
        *var_arg = 1;
        var_size = 3;
        break;
    case 2:
        *var_arg = 2;
        var_size = 3;
        break;
    case 3:
        *var_arg = 3;
        var_size = 3;
        break;
    case 4:
        *var_arg = 4;
        var_size = 3;
        break;
    case 5:
        *var_arg = 5;
        var_size = 3;
        break;
    case 6:
        *var_arg = 6;
        var_size = 3;
        break;
    case 7:
        *var_arg = 8;
        var_size = 3;
        break;
    default:
        var_hit = 0;
    }
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int mpeg4audio_channels::getvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_esc_bits = 0;
    int var_hit = 1;

    var_data = var_bs.nextbits(3);
    switch (var_data) {
    case 0:
        var_bs.skipbits(3);
        *var_arg = 0;
        var_size = 3;
        break;
    case 1:
        var_bs.skipbits(3);
        *var_arg = 1;
        var_size = 3;
        break;
    case 2:
        var_bs.skipbits(3);
        *var_arg = 2;
        var_size = 3;
        break;
    case 3:
        var_bs.skipbits(3);
        *var_arg = 3;
        var_size = 3;
        break;
    case 4:
        var_bs.skipbits(3);
        *var_arg = 4;
        var_size = 3;
        break;
    case 5:
        var_bs.skipbits(3);
        *var_arg = 5;
        var_size = 3;
        break;
    case 6:
        var_bs.skipbits(3);
        *var_arg = 6;
        var_size = 3;
        break;
    case 7:
        var_bs.skipbits(3);
        *var_arg = 8;
        var_size = 3;
        break;
    default:
        var_hit = 0;
    }
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int mpeg4audio_channels::putvlc(IBitstream &var_bs, unsigned int var_arg, int *var_parse, int *var_code) {
    int var_data = 0, var_size = 0;
    int var_esc_bits = 0;
    int var_hit = 1;

    if (var_arg == 0) {
        var_bs.putbits(0,3);
        var_size = 3;
        var_data = 0;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 1) {
        var_bs.putbits(1,3);
        var_size = 3;
        var_data = 1;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 2) {
        var_bs.putbits(2,3);
        var_size = 3;
        var_data = 2;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 3) {
        var_bs.putbits(3,3);
        var_size = 3;
        var_data = 3;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 4) {
        var_bs.putbits(4,3);
        var_size = 3;
        var_data = 4;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 5) {
        var_bs.putbits(5,3);
        var_size = 3;
        var_data = 5;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 6) {
        var_bs.putbits(6,3);
        var_size = 3;
        var_data = 6;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    if (var_arg == 8) {
        var_bs.putbits(7,3);
        var_size = 3;
        var_data = 7;
        if (var_parse != NULL) *var_parse = var_size;
        if (var_code != NULL) *var_code = var_data;
        return var_hit;
    }
    var_hit = 0;
    if (var_parse != NULL) *var_parse = var_size;
    if (var_code != NULL) *var_code = var_data;
    return var_hit;
}

int aac_info_mp4::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    object_type = var_bs.getbits(5);
    if (31==object_type) {
        object_type = var_bs.getbits(32);
    }
    
    if (mpeg4audio_sample_rates::getvlc(var_bs, &sample_rate) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_sample_rates' lookup for 'sample_rate' failed"));
        var_ret++;
    }
    channels_4_bit = var_bs.getbits(1);
    if (channels_4_bit != 0) {
        MG_ERROR(_T("Const value mismatch for 'channels_4_bit'"));
        var_ret++;
    }
    if (mpeg4audio_channels::getvlc(var_bs, &channels) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_channels' lookup for 'channels' failed"));
        var_ret++;
    }
    if (1==object_type||2==object_type)
    {
        frame_length_flag = var_bs.getbits(1);
        if (!frame_length_flag)
        {
            depends_core_coder = var_bs.getbits(1);
            if (depends_core_coder != 0) {
                MG_ERROR(_T("Const value mismatch for 'depends_core_coder'"));
                var_ret++;
            }
            if (depends_core_coder)
            {
                core_coder_delay = var_bs.getbits(14);
            }
            
            extension_flag = var_bs.getbits(1);
            if (extension_flag != 0) {
                MG_ERROR(_T("Const value mismatch for 'extension_flag'"));
                var_ret++;
            }
            ;
        }
        else
        {
            var_bs.skipbits(2);
        }
        
    }
    else
    {
        var_bs.skipbits(3);
    }
    
    return var_ret;
}

int aac_info_mp4::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_bs.putbits(object_type, 5);
    if (31==object_type) {
        var_bs.putbits(object_type, 32);
    }
    
    if (mpeg4audio_sample_rates::putvlc(var_bs, sample_rate) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_sample_rates' lookup for 'sample_rate' failed"));
        var_ret++;
    }
    var_parse = 1;
    channels_4_bit = 0;
    var_bs.putbits(channels_4_bit, var_parse);
    if (mpeg4audio_channels::putvlc(var_bs, channels) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_channels' lookup for 'channels' failed"));
        var_ret++;
    }
    if (1==object_type||2==object_type)
    {
        var_bs.putbits(frame_length_flag, 1);
        if (!frame_length_flag)
        {
            var_parse = 1;
            depends_core_coder = 0;
            var_bs.putbits(depends_core_coder, var_parse);
            if (depends_core_coder)
            {
                var_bs.putbits(core_coder_delay, 14);
            }
            
            var_parse = 1;
            extension_flag = 0;
            var_bs.putbits(extension_flag, var_parse);
            ;
        }
        else
        {
            var_bs.skipbits(2);
        }
        
    }
    else
    {
        var_bs.skipbits(3);
    }
    
    return var_ret;
}

int ADTS::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    syncword = var_bs.getbits(12);
    if (syncword != 4095) {
        MG_ERROR(_T("Const value mismatch for 'syncword'"));
        var_ret++;
    }
    mpeg_version = var_bs.getbits(1);
    layer = var_bs.getbits(2);
    if (layer != 0) {
        MG_ERROR(_T("Const value mismatch for 'layer'"));
        var_ret++;
    }
    missing_protection = var_bs.getbits(1);
    mpeg_4_audio_object_minus_1 = var_bs.getbits(2);
    if (mpeg4audio_sample_rates::getvlc(var_bs, &mpeg_4_sampling_frequency) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_sample_rates' lookup for 'mpeg_4_sampling_frequency' failed"));
        var_ret++;
    }
    private_bit = var_bs.getbits(1);
    if (mpeg4audio_channels::getvlc(var_bs, &channel_configuration) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_channels' lookup for 'channel_configuration' failed"));
        var_ret++;
    }
    private_bit_2 = var_bs.getbits(1);
    home = var_bs.getbits(1);
    copyrighted = var_bs.getbits(1);
    copyrighted_start = var_bs.getbits(1);
    frame_length = var_bs.getbits(13);
    buffer_fullnes = var_bs.getbits(11);
    aac_frames_minus_1 = var_bs.getbits(2);
    if (!missing_protection)
    {
        CRC = var_bs.getbits(16);
    }
    
    return var_ret;
}

int ADTS::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_parse = 12;
    syncword = 4095;
    var_bs.putbits(syncword, var_parse);
    var_bs.putbits(mpeg_version, 1);
    var_parse = 2;
    layer = 0;
    var_bs.putbits(layer, var_parse);
    var_bs.putbits(missing_protection, 1);
    var_bs.putbits(mpeg_4_audio_object_minus_1, 2);
    if (mpeg4audio_sample_rates::putvlc(var_bs, mpeg_4_sampling_frequency) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_sample_rates' lookup for 'mpeg_4_sampling_frequency' failed"));
        var_ret++;
    }
    var_bs.putbits(private_bit, 1);
    if (mpeg4audio_channels::putvlc(var_bs, channel_configuration) == 0) {
        MG_ERROR(_T("Map 'mpeg4audio_channels' lookup for 'channel_configuration' failed"));
        var_ret++;
    }
    var_bs.putbits(private_bit_2, 1);
    var_bs.putbits(home, 1);
    var_bs.putbits(copyrighted, 1);
    var_bs.putbits(copyrighted_start, 1);
    var_bs.putbits(frame_length, 13);
    var_bs.putbits(buffer_fullnes, 11);
    var_bs.putbits(aac_frames_minus_1, 2);
    if (!missing_protection)
    {
        var_bs.putbits(CRC, 16);
    }
    
    return var_ret;
}

__ALX_END_NAMESPACE
