/* @mediagen - Update README.md -
 *
 * mpeg2ts.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'mpeg2ts.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "mpeg2ts.h"


__ALX_BEGIN_NAMESPACE
const unsigned int private_stream_2 = 191;
const unsigned int padding_stream = 190;
const unsigned int extension_start_code = 437;
const unsigned int ST_PSMapTable = 444;
const unsigned int ST_Private1 = 445;
const unsigned int ST_Padding = 446;
const unsigned int ST_Private2 = 447;
const unsigned int ST_Audio1 = 448;
const unsigned int ST_Audio2 = 479;
const unsigned int ST_Video1 = 480;
const unsigned int ST_Video2 = 495;
const unsigned int ST_ECM = 496;
const unsigned int ST_EMM = 497;
const unsigned int ST_DSMCC = 498;
const unsigned int ST_ISO_13522 = 499;
const unsigned int ST_ITUT_A = 500;
const unsigned int ST_ITUT_B = 501;
const unsigned int ST_ITUT_C = 502;
const unsigned int ST_ITUT_D = 503;
const unsigned int ST_ITUT_E = 504;
const unsigned int ST_PSDirectory = 511;
const unsigned int fast_forward = 0;
const unsigned int slow_motion = 1;
const unsigned int freeze_frame = 2;
const unsigned int fast_reverse = 3;
const unsigned int slow_reverse = 4;

int MpegTime::get(IBitstream &var_bs) {
    int var_ret = 0;
    return var_ret;
}

int MpegTime::put(IBitstream &var_bs) {
    int var_ret = 0;
    return var_ret;
}

int SystemHeaderStream::get(IBitstream &var_bs) {
    int var_ret = 0;
    stream_id = var_bs.getbits(8);
    bit_pattern = var_bs.getbits(2);
    if (bit_pattern != 3) {
        MG_ERROR(_T("Const value mismatch for 'bit_pattern'"));
        var_ret++;
    }
    P_STD_buffer_bound_scale = var_bs.getbits(1);
    P_STD_buffer_size_bound = var_bs.getbits(13);
    return var_ret;
}

int SystemHeaderStream::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.putbits(stream_id, 8);
    var_parse = 2;
    bit_pattern = 3;
    var_bs.putbits(bit_pattern, var_parse);
    var_bs.putbits(P_STD_buffer_bound_scale, 1);
    var_bs.putbits(P_STD_buffer_size_bound, 13);
    return var_ret;
}

int SystemHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    packet_start_code_prefix = var_bs.getbits(24);
    if (packet_start_code_prefix != 1) {
        MG_ERROR(_T("Const value mismatch for 'packet_start_code_prefix'"));
        var_ret++;
    }
    id = var_bs.getbits(8);
    if (id != 187) {
        MG_ERROR(_T("Const value mismatch for 'id'"));
        var_ret++;
    }
    header_length = var_bs.getbits(16);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    rate_bound = var_bs.getbits(22);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    audio_bound = var_bs.getbits(6);
    fixed_flag = var_bs.getbits(1);
    CSPS_flag = var_bs.getbits(1);
    system_audio_lock_flag = var_bs.getbits(1);
    system_video_lock_flag = var_bs.getbits(1);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    video_bound = var_bs.getbits(5);
    packet_rate_restriction_flag = var_bs.getbits(1);
    reserved = var_bs.getbits(7);
    if (reserved != 127) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    i = 0;
    while (var_bs.next(1, 1, 0, 0)==1) {
        var_dim0 = i++;
        stream_id[var_dim0] = var_bs.getbits(8);
        if (stream_id[i]<188)
        {
            if (stream_id[i]!=184)
            {
                if (stream_id[i]!=185)
                {
                     
                    print_error(); 
                }
                
            }
            
        }
        
        bit_pattern = var_bs.getbits(2);
        if (bit_pattern != 3) {
            MG_ERROR(_T("Const value mismatch for 'bit_pattern'"));
            var_ret++;
        }
        var_dim0 = i;
        P_STD_buffer_bound_scale[var_dim0] = var_bs.getbits(1);
        var_dim0 = i;
        P_STD_buffer_size_bound[var_dim0] = var_bs.getbits(13);
    }
    return var_ret;
}

int SystemHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    int var_parse = 0;
    var_parse = 24;
    packet_start_code_prefix = 1;
    var_bs.putbits(packet_start_code_prefix, var_parse);
    var_parse = 8;
    id = 187;
    var_bs.putbits(id, var_parse);
    var_bs.putbits(header_length, 16);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(rate_bound, 22);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(audio_bound, 6);
    var_bs.putbits(fixed_flag, 1);
    var_bs.putbits(CSPS_flag, 1);
    var_bs.putbits(system_audio_lock_flag, 1);
    var_bs.putbits(system_video_lock_flag, 1);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(video_bound, 5);
    var_bs.putbits(packet_rate_restriction_flag, 1);
    var_parse = 7;
    reserved = 127;
    var_bs.putbits(reserved, var_parse);
    i = 0;
    while (var_bs.next(1, 1, 0, 0)==1) {
        var_dim0 = i++;
        var_bs.putbits(stream_id[var_dim0], 8);
        if (stream_id[i]<188)
        {
            if (stream_id[i]!=184)
            {
                if (stream_id[i]!=185)
                {
                }
                
            }
            
        }
        
        var_parse = 2;
        bit_pattern = 3;
        var_bs.putbits(bit_pattern, var_parse);
        var_dim0 = i;
        var_bs.putbits(P_STD_buffer_bound_scale[var_dim0], 1);
        var_dim0 = i;
        var_bs.putbits(P_STD_buffer_size_bound[var_dim0], 13);
    }
    return var_ret;
}

int PackHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    packet_start_code_prefix = var_bs.getbits(24);
    if (packet_start_code_prefix != 1) {
        MG_ERROR(_T("Const value mismatch for 'packet_start_code_prefix'"));
        var_ret++;
    }
    id = var_bs.getbits(8);
    if (id != 186) {
        MG_ERROR(_T("Const value mismatch for 'id'"));
        var_ret++;
    }
    bit_pattern = var_bs.getbits(2);
    if (bit_pattern != 1) {
        MG_ERROR(_T("Const value mismatch for 'bit_pattern'"));
        var_ret++;
    }
    system_clock_ref_1 = var_bs.getbits(3);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    system_clock_ref_2 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    system_clock_ref_3 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    system_clock_ref_extension = var_bs.getbits(9);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    program_mux_rate = var_bs.getbits(22);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    reserved = var_bs.getbits(5);
    stuffing_len = var_bs.getbits(3);
    for (i=0; i<stuffing_len; i++) {
        stuffing_byte = var_bs.getbits(8);
        if (stuffing_byte != 255) {
            MG_ERROR(_T("Const value mismatch for 'stuffing_byte'"));
            var_ret++;
        }
    }
    return var_ret;
}

int PackHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 24;
    packet_start_code_prefix = 1;
    var_bs.putbits(packet_start_code_prefix, var_parse);
    var_parse = 8;
    id = 186;
    var_bs.putbits(id, var_parse);
    var_parse = 2;
    bit_pattern = 1;
    var_bs.putbits(bit_pattern, var_parse);
    var_bs.putbits(system_clock_ref_1, 3);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(system_clock_ref_2, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(system_clock_ref_3, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(system_clock_ref_extension, 9);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(program_mux_rate, 22);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(reserved, 5);
    var_bs.putbits(stuffing_len, 3);
    for (i=0; i<stuffing_len; i++) {
        var_parse = 8;
        stuffing_byte = 255;
        var_bs.putbits(stuffing_byte, var_parse);
    }
    return var_ret;
}

int base_program_descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    tag = var_bs.getbits(8);
    length = var_bs.getbits(8);
    des_byte_count = 0;
    for (des_byte_count=0; des_byte_count<length; des_byte_count++) {
        var_dim0 = des_byte_count;
        descriptor_data_byte[var_dim0] = var_bs.getbits(8);
    }
    return var_ret;
}

int base_program_descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.putbits(tag, 8);
    var_bs.putbits(length, 8);
    des_byte_count = 0;
    for (des_byte_count=0; des_byte_count<length; des_byte_count++) {
        var_dim0 = des_byte_count;
        var_bs.putbits(descriptor_data_byte[var_dim0], 8);
    }
    return var_ret;
}

int BaseProgramDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    var_lengthof = var_bs.getpos();
    length = var_bs.getbits(8);
    var_lengthof = var_bs.getpos()-var_lengthof;
    return var_ret;
}

int BaseProgramDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    var_lengthof = var_bs.getpos();
    var_bs.putbits(length, 8);
    var_lengthof = var_bs.getpos()-var_lengthof;
    return var_ret;
}

int VideoDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 2) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    multiple_frame_rate_flag = var_bs.getbits(1);
    frame_rate_code = var_bs.getbits(4);
    MPEG1_only_flag = var_bs.getbits(1);
    constrained_parameter_flag = var_bs.getbits(1);
    still_picture_flag = var_bs.getbits(1);
    if (MPEG1_only_flag==1)
    {
        profile_and_level_indication = var_bs.getbits(8);
        chroma_format = var_bs.getbits(2);
        frame_rate_extension_flag = var_bs.getbits(1);
        reserved = var_bs.getbits(5);
    }
    
    return var_ret;
}

int VideoDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 2;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(multiple_frame_rate_flag, 1);
    var_bs.putbits(frame_rate_code, 4);
    var_bs.putbits(MPEG1_only_flag, 1);
    var_bs.putbits(constrained_parameter_flag, 1);
    var_bs.putbits(still_picture_flag, 1);
    if (MPEG1_only_flag==1)
    {
        var_bs.putbits(profile_and_level_indication, 8);
        var_bs.putbits(chroma_format, 2);
        var_bs.putbits(frame_rate_extension_flag, 1);
        var_bs.putbits(reserved, 5);
    }
    
    return var_ret;
}

int AudioDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 3) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    free_format_flag = var_bs.getbits(1);
    ID = var_bs.getbits(1);
    layer = var_bs.getbits(2);
    variable_rate_audio_indicator = var_bs.getbits(1);
    reserved = var_bs.getbits(3);
    return var_ret;
}

int AudioDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 3;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(free_format_flag, 1);
    var_bs.putbits(ID, 1);
    var_bs.putbits(layer, 2);
    var_bs.putbits(variable_rate_audio_indicator, 1);
    var_bs.putbits(reserved, 3);
    return var_ret;
}

int HierarchyDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 4) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    reserved = var_bs.getbits(4);
    hierarchy_type = var_bs.getbits(4);
    reserved = var_bs.getbits(2);
    hierarchy_layer_index = var_bs.getbits(6);
    reserved = var_bs.getbits(2);
    hierarchy_embedded_layer_index = var_bs.getbits(6);
    reserved = var_bs.getbits(2);
    hierarchy_channel = var_bs.getbits(6);
    return var_ret;
}

int HierarchyDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 4;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(reserved, 4);
    var_bs.putbits(hierarchy_type, 4);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(hierarchy_layer_index, 6);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(hierarchy_embedded_layer_index, 6);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(hierarchy_channel, 6);
    return var_ret;
}

int RegistrationDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 5) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    format_identifier = var_bs.getbits(32);
    for (bytes_read=4; bytes_read<length; ) {
        additional_identification_info = var_bs.getbits(8);
        bytes_read+=1;
    }
    return var_ret;
}

int RegistrationDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 5;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(format_identifier, 32);
    for (bytes_read=4; bytes_read<length; ) {
        var_bs.putbits(additional_identification_info, 8);
        bytes_read+=1;
    }
    return var_ret;
}

int DataAlignmentDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 6) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    alignment_type = var_bs.getbits(8);
    return var_ret;
}

int DataAlignmentDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 6;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(alignment_type, 8);
    return var_ret;
}

int TargetBackgroundGridDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 7) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    horizontal_size = var_bs.getbits(14);
    vertical_size = var_bs.getbits(14);
    aspect_ratio_information = var_bs.getbits(4);
    return var_ret;
}

int TargetBackgroundGridDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 7;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(horizontal_size, 14);
    var_bs.putbits(vertical_size, 14);
    var_bs.putbits(aspect_ratio_information, 4);
    return var_ret;
}

int VideoWindowDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 8) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    horizontal_offset = var_bs.getbits(14);
    vertical_offset = var_bs.getbits(14);
    window_priority = var_bs.getbits(4);
    return var_ret;
}

int VideoWindowDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 8;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(horizontal_offset, 14);
    var_bs.putbits(vertical_offset, 14);
    var_bs.putbits(window_priority, 4);
    return var_ret;
}

int ConditionalAccessDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 9) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    CA_system_ID = var_bs.getbits(16);
    reserved = var_bs.getbits(3);
    CA_PID = var_bs.getbits(13);
    for (bytes_read=4; bytes_read<length; ) {
        private_data_byte = var_bs.getbits(8);
        bytes_read+=1;
    }
    return var_ret;
}

int ConditionalAccessDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 9;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(CA_system_ID, 16);
    var_bs.putbits(reserved, 3);
    var_bs.putbits(CA_PID, 13);
    for (bytes_read=4; bytes_read<length; ) {
        var_bs.putbits(private_data_byte, 8);
        bytes_read+=1;
    }
    return var_ret;
}

int LanguageDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 10) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    for (bytes_read=0; bytes_read<length; ) {
        ISO_639_language_code = var_bs.getbits(24);
        audio_type = var_bs.getbits(8);
        bytes_read+=4;
    }
    return var_ret;
}

int LanguageDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 10;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    for (bytes_read=0; bytes_read<length; ) {
        var_bs.putbits(ISO_639_language_code, 24);
        var_bs.putbits(audio_type, 8);
        bytes_read+=4;
    }
    return var_ret;
}

int SystemClockDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 11) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    external_clock_reference_indicator = var_bs.getbits(1);
    reserved = var_bs.getbits(1);
    clock_accuracy_indicator = var_bs.getbits(6);
    clock_accuracy_exponent = var_bs.getbits(3);
    reserved = var_bs.getbits(5);
    return var_ret;
}

int SystemClockDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 11;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(external_clock_reference_indicator, 1);
    var_bs.putbits(reserved, 1);
    var_bs.putbits(clock_accuracy_indicator, 6);
    var_bs.putbits(clock_accuracy_exponent, 3);
    var_bs.putbits(reserved, 5);
    return var_ret;
}

int MultiplexBufferUtilizationDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 12) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    bound_valid_flag = var_bs.getbits(1);
    LTW_offset_lower_bound = var_bs.getbits(15);
    reserved = var_bs.getbits(1);
    LTW_offset_upper_bound = var_bs.getbits(15);
    return var_ret;
}

int MultiplexBufferUtilizationDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 12;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(bound_valid_flag, 1);
    var_bs.putbits(LTW_offset_lower_bound, 15);
    var_bs.putbits(reserved, 1);
    var_bs.putbits(LTW_offset_upper_bound, 15);
    return var_ret;
}

int CopyrightDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 13) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    copyright_identifier = var_bs.getbits(32);
    for (bytes_read=4; bytes_read<length; ) {
        additional_copyright_info = var_bs.getbits(8);
        bytes_read+=1;
    }
    return var_ret;
}

int CopyrightDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 13;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(copyright_identifier, 32);
    for (bytes_read=4; bytes_read<length; ) {
        var_bs.putbits(additional_copyright_info, 8);
        bytes_read+=1;
    }
    return var_ret;
}

int MaximumBitrateDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 14) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    reserved = var_bs.getbits(2);
    maximum_bitrate = var_bs.getbits(22);
    return var_ret;
}

int MaximumBitrateDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 14;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(maximum_bitrate, 22);
    return var_ret;
}

int PrivateDataIndicatorDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 15) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    private_data_indicator = var_bs.getbits(32);
    return var_ret;
}

int PrivateDataIndicatorDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 15;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(private_data_indicator, 32);
    return var_ret;
}

int SmoothingBufferDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 16) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    reserved = var_bs.getbits(2);
    sb_leak_rate = var_bs.getbits(22);
    reserved = var_bs.getbits(2);
    sb_size = var_bs.getbits(22);
    return var_ret;
}

int SmoothingBufferDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 16;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(sb_leak_rate, 22);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(sb_size, 22);
    return var_ret;
}

int STDDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 17) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    reserved = var_bs.getbits(7);
    leak_valid_flag = var_bs.getbits(1);
    return var_ret;
}

int STDDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 17;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(reserved, 7);
    var_bs.putbits(leak_valid_flag, 1);
    return var_ret;
}

int IBPDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        tag = var_bs.getbits(8);
        if (tag != 18) {
            MG_ERROR(_T("Const value mismatch for 'tag'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::get(var_bs, var_id_parsed);
    closed_gop_flag = var_bs.getbits(1);
    identical_gop_flag = var_bs.getbits(1);
    max_gop_length = var_bs.getbits(14);
    return var_ret;
}

int IBPDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        tag = 18;
        var_bs.putbits(tag, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseProgramDescriptor::put(var_bs, var_id_parsed);
    var_bs.putbits(closed_gop_flag, 1);
    var_bs.putbits(identical_gop_flag, 1);
    var_bs.putbits(max_gop_length, 14);
    return var_ret;
}

int base_stream_descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    elementary_stream_id = var_bs.getbits(8);
    elementary_stream_info_length = var_bs.getbits(16);
    parsedBytes = 0;
    for (parsedBytes=0; parsedBytes<elementary_stream_info_length; ) {
        descriptor = new(base_program_descriptor);
        var_ret += descriptor->get(var_bs);
        
			_program_descriptor.push_back(descriptor);
			parsedBytes += (descriptor->length + 2);
	   
    }
    return var_ret;
}

int base_stream_descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.putbits(elementary_stream_id, 8);
    var_bs.putbits(elementary_stream_info_length, 16);
    parsedBytes = 0;
     
			unsigned int descriptor_count = 0;
		
    for (parsedBytes=0; parsedBytes<elementary_stream_info_length; ) {
        
		   descriptor      = _program_descriptor[descriptor_count++];
		   parsedBytes += (descriptor->length + 2);
	   
        var_ret += descriptor->put(var_bs);
    }
    return var_ret;
}

int BaseStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_descriptor_id;
    var_lengthof = var_bs.getpos();
    elementary_stream_id = var_bs.getbits(8);
    elementary_stream_info_length = var_bs.getbits(16);
    for (parsedBytes=0; parsedBytes<elementary_stream_info_length; ) {
        var_descriptor_id = var_bs.nextbits(8);
        if (var_descriptor_id == 2) {
            descriptor = new(VideoDescriptor);
        }
        else if (var_descriptor_id == 3) {
            descriptor = new(AudioDescriptor);
        }
        else if (var_descriptor_id == 4) {
            descriptor = new(HierarchyDescriptor);
        }
        else if (var_descriptor_id == 5) {
            descriptor = new(RegistrationDescriptor);
        }
        else if (var_descriptor_id == 6) {
            descriptor = new(DataAlignmentDescriptor);
        }
        else if (var_descriptor_id == 7) {
            descriptor = new(TargetBackgroundGridDescriptor);
        }
        else if (var_descriptor_id == 8) {
            descriptor = new(VideoWindowDescriptor);
        }
        else if (var_descriptor_id == 9) {
            descriptor = new(ConditionalAccessDescriptor);
        }
        else if (var_descriptor_id == 10) {
            descriptor = new(LanguageDescriptor);
        }
        else if (var_descriptor_id == 11) {
            descriptor = new(SystemClockDescriptor);
        }
        else if (var_descriptor_id == 12) {
            descriptor = new(MultiplexBufferUtilizationDescriptor);
        }
        else if (var_descriptor_id == 13) {
            descriptor = new(CopyrightDescriptor);
        }
        else if (var_descriptor_id == 14) {
            descriptor = new(MaximumBitrateDescriptor);
        }
        else if (var_descriptor_id == 15) {
            descriptor = new(PrivateDataIndicatorDescriptor);
        }
        else if (var_descriptor_id == 16) {
            descriptor = new(SmoothingBufferDescriptor);
        }
        else if (var_descriptor_id == 17) {
            descriptor = new(STDDescriptor);
        }
        else if (var_descriptor_id == 18) {
            descriptor = new(IBPDescriptor);
        }
        else {
            MG_ERROR1(_T("Unknown ID value for class 'descriptor' of type 'BaseProgramDescriptor': %d\n"), var_descriptor_id);
            descriptor = new(BaseProgramDescriptor);
        }
        var_ret += descriptor->get(var_bs);
        parsedBytes+=descriptor->var_lengthof;
    }
    var_lengthof = var_bs.getpos()-var_lengthof;
    return var_ret;
}

int BaseStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    var_lengthof = var_bs.getpos();
    var_bs.putbits(elementary_stream_id, 8);
    var_bs.putbits(elementary_stream_info_length, 16);
    for (parsedBytes=0; parsedBytes<elementary_stream_info_length; ) {
        var_ret += descriptor->put(var_bs);
        parsedBytes+=descriptor->var_lengthof;
    }
    var_lengthof = var_bs.getpos()-var_lengthof;
    return var_ret;
}

int MPEG1VideoStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 1) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG1VideoStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 1;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG2VideoStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 2) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG2VideoStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 2;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG1AudioStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 3) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG1AudioStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 3;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG2AudioStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 4) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int MPEG2AudioStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 4;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int PrivateStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 5) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int PrivateStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 5;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int PrivatePESDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 6) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int PrivatePESDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 6;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int MHEGStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 7) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int MHEGStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 7;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int DSMCCStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 8) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int DSMCCStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 8;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int H222_1StreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 9) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int H222_1StreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 9;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int ATypeStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 10) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int ATypeStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 10;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int BTypeStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 11) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int BTypeStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 11;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int CTypeStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 12) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int CTypeStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 12;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int DTypeStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 13) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int DTypeStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 13;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int AuxiliaryStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (type != 14) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int AuxiliaryStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        type = 14;
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int ReservedStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (!(15 <= type && type <= 127)) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int ReservedStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        if (!(15 <= type && type <= 127)) {
            type = 15;
        }
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int UserPrivateStreamDescriptor::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        type = var_bs.getbits(8);
        if (!(128 <= type && type <= 255)) {
            MG_ERROR(_T("Const value mismatch for 'type'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::get(var_bs, var_id_parsed);
    return var_ret;
}

int UserPrivateStreamDescriptor::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 8;
        if (!(128 <= type && type <= 255)) {
            type = 128;
        }
        var_bs.putbits(type, var_parse);
        var_id_parsed = 1;
    }
    var_ret += BaseStreamDescriptor::put(var_bs, var_id_parsed);
    return var_ret;
}

int TrickModeControl::get(IBitstream &var_bs) {
    int var_ret = 0;
    trick_mode_control = var_bs.getbits(3);
    if (trick_mode_control==0||trick_mode_control==3)
    {
        field_id = var_bs.getbits(2);
        intra_slice_refresh = var_bs.getbits(1);
        frequency_truncation = var_bs.getbits(2);
    }
    else {
        if (trick_mode_control==1) {
            rep_ctrl = var_bs.getbits(5);
        }
        else {
            if (trick_mode_control==2)
            {
                field_id = var_bs.getbits(2);
                reserved = var_bs.getbits(3);
            }
            else {
                if (trick_mode_control==4) {
                    rep_ctrl = var_bs.getbits(5);
                }
                else {
                    reserved = var_bs.getbits(5);
                }
                
            }
            
        }
        
    }
    
    return var_ret;
}

int TrickModeControl::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.putbits(trick_mode_control, 3);
    if (trick_mode_control==0||trick_mode_control==3)
    {
        var_bs.putbits(field_id, 2);
        var_bs.putbits(intra_slice_refresh, 1);
        var_bs.putbits(frequency_truncation, 2);
    }
    else {
        if (trick_mode_control==1) {
            var_bs.putbits(rep_ctrl, 5);
        }
        else {
            if (trick_mode_control==2)
            {
                var_bs.putbits(field_id, 2);
                var_bs.putbits(reserved, 3);
            }
            else {
                if (trick_mode_control==4) {
                    var_bs.putbits(rep_ctrl, 5);
                }
                else {
                    var_bs.putbits(reserved, 5);
                }
                
            }
            
        }
        
    }
    
    return var_ret;
}

int PesBase::get(IBitstream &var_bs) {
    int var_ret = 0;
    packet_start_code_prefix = var_bs.getbits(24);
    if (packet_start_code_prefix != 1) {
        MG_ERROR(_T("Const value mismatch for 'packet_start_code_prefix'"));
        var_ret++;
    }
    stream_id = var_bs.getbits(8);
    PES_packet_length = var_bs.getbits(16);
    return var_ret;
}

int PesBase::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 24;
    packet_start_code_prefix = 1;
    var_bs.putbits(packet_start_code_prefix, var_parse);
    var_bs.putbits(stream_id, 8);
    var_bs.putbits(PES_packet_length, 16);
    return var_ret;
}

int PSMapTable::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_stream_descriptor_id;
    int var_program_descriptor_id;
    var_ret += PesBase::get(var_bs);
    if (PES_packet_length>1018)
    {
         
        print_error(); 
    }
    
    current_next_indicator = var_bs.getbits(1);
    reserved = var_bs.getbits(2);
    program_stream_map_version = var_bs.getbits(5);
    reserved = var_bs.getbits(7);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    program_stream_info_length = var_bs.getbits(16);
    for (parsed=0; parsed<program_stream_info_length; ) {
        var_program_descriptor_id = var_bs.nextbits(8);
        if (var_program_descriptor_id == 2) {
            program_descriptor = new(VideoDescriptor);
        }
        else if (var_program_descriptor_id == 3) {
            program_descriptor = new(AudioDescriptor);
        }
        else if (var_program_descriptor_id == 4) {
            program_descriptor = new(HierarchyDescriptor);
        }
        else if (var_program_descriptor_id == 5) {
            program_descriptor = new(RegistrationDescriptor);
        }
        else if (var_program_descriptor_id == 6) {
            program_descriptor = new(DataAlignmentDescriptor);
        }
        else if (var_program_descriptor_id == 7) {
            program_descriptor = new(TargetBackgroundGridDescriptor);
        }
        else if (var_program_descriptor_id == 8) {
            program_descriptor = new(VideoWindowDescriptor);
        }
        else if (var_program_descriptor_id == 9) {
            program_descriptor = new(ConditionalAccessDescriptor);
        }
        else if (var_program_descriptor_id == 10) {
            program_descriptor = new(LanguageDescriptor);
        }
        else if (var_program_descriptor_id == 11) {
            program_descriptor = new(SystemClockDescriptor);
        }
        else if (var_program_descriptor_id == 12) {
            program_descriptor = new(MultiplexBufferUtilizationDescriptor);
        }
        else if (var_program_descriptor_id == 13) {
            program_descriptor = new(CopyrightDescriptor);
        }
        else if (var_program_descriptor_id == 14) {
            program_descriptor = new(MaximumBitrateDescriptor);
        }
        else if (var_program_descriptor_id == 15) {
            program_descriptor = new(PrivateDataIndicatorDescriptor);
        }
        else if (var_program_descriptor_id == 16) {
            program_descriptor = new(SmoothingBufferDescriptor);
        }
        else if (var_program_descriptor_id == 17) {
            program_descriptor = new(STDDescriptor);
        }
        else if (var_program_descriptor_id == 18) {
            program_descriptor = new(IBPDescriptor);
        }
        else {
            MG_ERROR1(_T("Unknown ID value for class 'program_descriptor' of type 'BaseProgramDescriptor': %d\n"), var_program_descriptor_id);
            program_descriptor = new(BaseProgramDescriptor);
        }
        var_ret += program_descriptor->get(var_bs);
        parsed+=program_descriptor->var_lengthof;
    }
    elementary_stream_map_length = var_bs.getbits(16);
    for (stream_map_ct=0; stream_map_ct<elementary_stream_map_length; ) {
        var_stream_descriptor_id = var_bs.nextbits(8);
        if (var_stream_descriptor_id == 1) {
            stream_descriptor = new(MPEG1VideoStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 2) {
            stream_descriptor = new(MPEG2VideoStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 3) {
            stream_descriptor = new(MPEG1AudioStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 4) {
            stream_descriptor = new(MPEG2AudioStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 5) {
            stream_descriptor = new(PrivateStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 6) {
            stream_descriptor = new(PrivatePESDescriptor);
        }
        else if (var_stream_descriptor_id == 7) {
            stream_descriptor = new(MHEGStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 8) {
            stream_descriptor = new(DSMCCStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 9) {
            stream_descriptor = new(H222_1StreamDescriptor);
        }
        else if (var_stream_descriptor_id == 10) {
            stream_descriptor = new(ATypeStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 11) {
            stream_descriptor = new(BTypeStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 12) {
            stream_descriptor = new(CTypeStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 13) {
            stream_descriptor = new(DTypeStreamDescriptor);
        }
        else if (var_stream_descriptor_id == 14) {
            stream_descriptor = new(AuxiliaryStreamDescriptor);
        }
        else if (15 <= var_stream_descriptor_id && var_stream_descriptor_id <= 127) {
            stream_descriptor = new(ReservedStreamDescriptor);
        }
        else if (128 <= var_stream_descriptor_id && var_stream_descriptor_id <= 255) {
            stream_descriptor = new(UserPrivateStreamDescriptor);
        }
        else {
            MG_ERROR1(_T("Unknown ID value for class 'stream_descriptor' of type 'BaseStreamDescriptor': %d\n"), var_stream_descriptor_id);
            stream_descriptor = new(BaseStreamDescriptor);
        }
        var_ret += stream_descriptor->get(var_bs);
        stream_map_ct+=stream_descriptor->var_lengthof;
    }
    CRC_32 = var_bs.getbits(32);
    return var_ret;
}

int PSMapTable::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_ret += PesBase::put(var_bs);
    if (PES_packet_length>1018)
    {
    }
    
    var_bs.putbits(current_next_indicator, 1);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(program_stream_map_version, 5);
    var_bs.putbits(reserved, 7);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(program_stream_info_length, 16);
    for (parsed=0; parsed<program_stream_info_length; ) {
        var_ret += program_descriptor->put(var_bs);
        parsed+=program_descriptor->var_lengthof;
    }
    var_bs.putbits(elementary_stream_map_length, 16);
    for (stream_map_ct=0; stream_map_ct<elementary_stream_map_length; ) {
        var_ret += stream_descriptor->put(var_bs);
        stream_map_ct+=stream_descriptor->var_lengthof;
    }
    var_bs.putbits(CRC_32, 32);
    return var_ret;
}

int PSDirectory::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PesBase::get(var_bs);
    number_of_access_units = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_1 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_2 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_3 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_4 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_5 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    previous_directory_offset_6 = var_bs.getbits(15);
    marker = var_bs.getbits(1);
    if (marker != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker'"));
        var_ret++;
    }
    for (i=0; i<number_of_access_units; i++) {
        packet_stream_id = var_bs.getbits(8);
        PES_header_position_offset_sign = var_bs.sgetbits(1);
        PES_header_position_offset_1 = var_bs.getbits(14);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        PES_header_position_offset_2 = var_bs.getbits(15);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        PES_header_position_offset_3 = var_bs.getbits(15);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        reference_offset = var_bs.getbits(16);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        reserved = var_bs.getbits(3);
        PTS_1 = var_bs.getbits(3);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        PTS_2 = var_bs.getbits(15);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        PTS_3 = var_bs.getbits(15);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        bytes_to_read = var_bs.getbits(15);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        bytes_to_read = var_bs.getbits(8);
        marker = var_bs.getbits(1);
        if (marker != 1) {
            MG_ERROR(_T("Const value mismatch for 'marker'"));
            var_ret++;
        }
        intra_coded_indicator = var_bs.getbits(1);
        coding_parameters_indicator = var_bs.getbits(2);
        reserved = var_bs.getbits(4);
    }
    return var_ret;
}

int PSDirectory::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_ret += PesBase::put(var_bs);
    var_bs.putbits(number_of_access_units, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_1, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_2, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_3, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_4, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_5, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    var_bs.putbits(previous_directory_offset_6, 15);
    var_parse = 1;
    marker = 1;
    var_bs.putbits(marker, var_parse);
    for (i=0; i<number_of_access_units; i++) {
        var_bs.putbits(packet_stream_id, 8);
        var_bs.putbits(PES_header_position_offset_sign, 1);
        var_bs.putbits(PES_header_position_offset_1, 14);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(PES_header_position_offset_2, 15);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(PES_header_position_offset_3, 15);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(reference_offset, 16);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(reserved, 3);
        var_bs.putbits(PTS_1, 3);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(PTS_2, 15);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(PTS_3, 15);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(bytes_to_read, 15);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(bytes_to_read, 8);
        var_parse = 1;
        marker = 1;
        var_bs.putbits(marker, var_parse);
        var_bs.putbits(intra_coded_indicator, 1);
        var_bs.putbits(coding_parameters_indicator, 2);
        var_bs.putbits(reserved, 4);
    }
    return var_ret;
}

int PesData::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PesBase::get(var_bs);
    if (stream_id!=191&&stream_id!=190)
    {
        check = var_bs.getbits(2);
        if (check != 2) {
            MG_ERROR(_T("Const value mismatch for 'check'"));
            var_ret++;
        }
        PES_scrambling_control = var_bs.getbits(2);
        PES_priority = var_bs.getbits(1);
        data_alignment_indicator = var_bs.getbits(1);
        copyright = var_bs.getbits(1);
        original_or_copy = var_bs.getbits(1);
        PTS_flags = var_bs.getbits(1);
        DTS_flags = var_bs.getbits(1);
        ESCR_flag = var_bs.getbits(1);
        ES_rate_flag = var_bs.getbits(1);
        DSM_trick_mode_flag = var_bs.getbits(1);
        additional_copy_info_flag = var_bs.getbits(1);
        PES_CRC_flag = var_bs.getbits(1);
        PES_extension_flag = var_bs.getbits(1);
        PES_header_data_length = var_bs.getbits(8);
        unsigned int size;
        size=0;
        if (PTS_flags)
        {
            check2 = var_bs.getbits(4);
            if (check2 != 3&(2|DTS_flags)) {
                MG_ERROR(_T("Const value mismatch for 'check2'"));
                var_ret++;
            }
            PTS_32_30 = var_bs.getbits(3);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            PTS_29_15 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            PTS_14_0 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            size+=40;
        }
        
        if (DTS_flags)
        {
            check2 = var_bs.getbits(4);
            if (check2 != 1) {
                MG_ERROR(_T("Const value mismatch for 'check2'"));
                var_ret++;
            }
            DTS_32_30 = var_bs.getbits(3);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            DTS_29_15 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            DTS_14_0 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            size+=40;
        }
        
        if (ESCR_flag)
        {
            reserved = var_bs.getbits(2);
            ESCR_base_32_30 = var_bs.getbits(3);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            ESCR_base_29_15 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            ESCR_base_14_0 = var_bs.getbits(15);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            ESCR_extension = var_bs.getbits(9);
            marker_bit = var_bs.getbits(1);
            size+=48;
        }
        
        if (ES_rate_flag)
        {
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            ES_rate = var_bs.getbits(22);
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            size+=24;
        }
        
        if (DSM_trick_mode_flag==1)
        {
            trick_mode_control = var_bs.getbits(3);
            if (trick_mode_control==0)
            {
                field_id = var_bs.getbits(2);
                intra_slice_refresh = var_bs.getbits(1);
                frequency_truncation = var_bs.getbits(2);
            }
            else {
                if (trick_mode_control==1)
                {
                    field_rep_cntrl = var_bs.getbits(5);
                }
                else {
                    if (trick_mode_control==2)
                    {
                        field_id = var_bs.getbits(2);
                        reserved = var_bs.getbits(3);
                    }
                    else {
                        if (trick_mode_control==3)
                        {
                            field_id = var_bs.getbits(2);
                            intra_slice_refresh = var_bs.getbits(1);
                            frequency_truncation = var_bs.getbits(2);
                        }
                        
                    }
                    
                }
                
            }
            
            size+=8;
        }
        
        if (additional_copy_info_flag==1)
        {
            marker_bit = var_bs.getbits(1);
            if (marker_bit != 1) {
                MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
                var_ret++;
            }
            additional_copy_info = var_bs.getbits(7);
            size+=8;
        }
        
        if (PES_CRC_flag==1)
        {
            previous_PES_packet_CRC = var_bs.getbits(16);
            size+=8;
        }
        
        if (PES_extension_flag==1)
        {
            PES_private_data_flag = var_bs.getbits(1);
            pack_header_field_flag = var_bs.getbits(1);
            program_packet_sequence_counter_flag = var_bs.getbits(1);
            P_STD_buffer_flag = var_bs.getbits(1);
            reserved_Pes = var_bs.getbits(3);
            PES_extension_field_flag = var_bs.getbits(1);
            size+=8;
            if (PES_private_data_flag==1)
            {
                PES_private_data_1 = var_bs.getbits(32);
                PES_private_data_2 = var_bs.getbits(32);
                PES_private_data_3 = var_bs.getbits(32);
                PES_private_data_4 = var_bs.getbits(32);
                size+=128;
            }
            
            if (pack_header_field_flag==1)
            {
                pack_field_length = var_bs.getbits(8);
                var_bs.skipbits(pack_field_length*8);
                size+=8;
                size+=(pack_field_length*8);
            }
            
            if (program_packet_sequence_counter_flag==1)
            {
                marker_bit = var_bs.getbits(1);
                program_packet_sequence_counter = var_bs.getbits(7);
                marker_bit = var_bs.getbits(1);
                original_stuff_length = var_bs.getbits(7);
                size+=16;
            }
            
            if (P_STD_buffer_flag==1)
            {
                P_STD_Reserved = var_bs.getbits(2);
                if (P_STD_Reserved != 1) {
                    MG_ERROR(_T("Const value mismatch for 'P_STD_Reserved'"));
                    var_ret++;
                }
                P_STD_buffer_scale = var_bs.getbits(1);
                P_STD_buffer_size = var_bs.getbits(13);
                size+=16;
            }
            
            if (PES_extension_field_flag==1)
            {
                marker_bit = var_bs.getbits(1);
                PES_extension_field_length = var_bs.getbits(7);
                unsigned int PES_extension_field_count;
                PES_extension_field_count = 0;
                for (PES_extension_field_count=0; PES_extension_field_count<PES_extension_field_length; PES_extension_field_count++) {
                    reserved = var_bs.getbits(8);
                }
                size+=8;
                size+=(PES_extension_field_length*8);
            }
            
        }
        
        size=(PES_header_data_length*8)-size;
        unsigned int i;
        for (i=0; i<(size/8); i++) {
            stuffing_byte = var_bs.getbits(8);
            if (stuffing_byte != 255) {
                MG_ERROR(_T("Const value mismatch for 'stuffing_byte'"));
                var_ret++;
            }
        }
    }
    
    return var_ret;
}

int PesData::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_ret += PesBase::put(var_bs);
    if (stream_id!=191&&stream_id!=190)
    {
        var_parse = 2;
        check = 2;
        var_bs.putbits(check, var_parse);
        var_bs.putbits(PES_scrambling_control, 2);
        var_bs.putbits(PES_priority, 1);
        var_bs.putbits(data_alignment_indicator, 1);
        var_bs.putbits(copyright, 1);
        var_bs.putbits(original_or_copy, 1);
        var_bs.putbits(PTS_flags, 1);
        var_bs.putbits(DTS_flags, 1);
        var_bs.putbits(ESCR_flag, 1);
        var_bs.putbits(ES_rate_flag, 1);
        var_bs.putbits(DSM_trick_mode_flag, 1);
        var_bs.putbits(additional_copy_info_flag, 1);
        var_bs.putbits(PES_CRC_flag, 1);
        var_bs.putbits(PES_extension_flag, 1);
        var_bs.putbits(PES_header_data_length, 8);
        unsigned int size;
        size=0;
        if (PTS_flags)
        {
            var_parse = 4;
            check2 = 3&(2|DTS_flags);
            var_bs.putbits(check2, var_parse);
            var_bs.putbits(PTS_32_30, 3);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(PTS_29_15, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(PTS_14_0, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            size+=40;
        }
        
        if (DTS_flags)
        {
            var_parse = 4;
            check2 = 1;
            var_bs.putbits(check2, var_parse);
            var_bs.putbits(DTS_32_30, 3);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(DTS_29_15, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(DTS_14_0, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            size+=40;
        }
        
        if (ESCR_flag)
        {
            var_bs.putbits(reserved, 2);
            var_bs.putbits(ESCR_base_32_30, 3);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(ESCR_base_29_15, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(ESCR_base_14_0, 15);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(ESCR_extension, 9);
            var_bs.putbits(marker_bit, 1);
            size+=48;
        }
        
        if (ES_rate_flag)
        {
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(ES_rate, 22);
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            size+=24;
        }
        
        if (DSM_trick_mode_flag==1)
        {
            var_bs.putbits(trick_mode_control, 3);
            if (trick_mode_control==0)
            {
                var_bs.putbits(field_id, 2);
                var_bs.putbits(intra_slice_refresh, 1);
                var_bs.putbits(frequency_truncation, 2);
            }
            else {
                if (trick_mode_control==1)
                {
                    var_bs.putbits(field_rep_cntrl, 5);
                }
                else {
                    if (trick_mode_control==2)
                    {
                        var_bs.putbits(field_id, 2);
                        var_bs.putbits(reserved, 3);
                    }
                    else {
                        if (trick_mode_control==3)
                        {
                            var_bs.putbits(field_id, 2);
                            var_bs.putbits(intra_slice_refresh, 1);
                            var_bs.putbits(frequency_truncation, 2);
                        }
                        
                    }
                    
                }
                
            }
            
            size+=8;
        }
        
        if (additional_copy_info_flag==1)
        {
            var_parse = 1;
            marker_bit = 1;
            var_bs.putbits(marker_bit, var_parse);
            var_bs.putbits(additional_copy_info, 7);
            size+=8;
        }
        
        if (PES_CRC_flag==1)
        {
            var_bs.putbits(previous_PES_packet_CRC, 16);
            size+=8;
        }
        
        if (PES_extension_flag==1)
        {
            var_bs.putbits(PES_private_data_flag, 1);
            var_bs.putbits(pack_header_field_flag, 1);
            var_bs.putbits(program_packet_sequence_counter_flag, 1);
            var_bs.putbits(P_STD_buffer_flag, 1);
            var_bs.putbits(reserved_Pes, 3);
            var_bs.putbits(PES_extension_field_flag, 1);
            size+=8;
            if (PES_private_data_flag==1)
            {
                var_bs.putbits(PES_private_data_1, 32);
                var_bs.putbits(PES_private_data_2, 32);
                var_bs.putbits(PES_private_data_3, 32);
                var_bs.putbits(PES_private_data_4, 32);
                size+=128;
            }
            
            if (pack_header_field_flag==1)
            {
                var_bs.putbits(pack_field_length, 8);
                var_bs.skipbits(pack_field_length*8);
                size+=8;
                size+=(pack_field_length*8);
            }
            
            if (program_packet_sequence_counter_flag==1)
            {
                var_bs.putbits(marker_bit, 1);
                var_bs.putbits(program_packet_sequence_counter, 7);
                var_bs.putbits(marker_bit, 1);
                var_bs.putbits(original_stuff_length, 7);
                size+=16;
            }
            
            if (P_STD_buffer_flag==1)
            {
                var_parse = 2;
                P_STD_Reserved = 1;
                var_bs.putbits(P_STD_Reserved, var_parse);
                var_bs.putbits(P_STD_buffer_scale, 1);
                var_bs.putbits(P_STD_buffer_size, 13);
                size+=16;
            }
            
            if (PES_extension_field_flag==1)
            {
                var_bs.putbits(marker_bit, 1);
                var_bs.putbits(PES_extension_field_length, 7);
                unsigned int PES_extension_field_count;
                PES_extension_field_count = 0;
                for (PES_extension_field_count=0; PES_extension_field_count<PES_extension_field_length; PES_extension_field_count++) {
                    var_bs.putbits(reserved, 8);
                }
                size+=8;
                size+=(PES_extension_field_length*8);
            }
            
        }
        
        size=(PES_header_data_length*8)-size;
        unsigned int i;
        for (i=0; i<(size/8); i++) {
            var_parse = 8;
            stuffing_byte = 255;
            var_bs.putbits(stuffing_byte, var_parse);
        }
    }
    
    return var_ret;
}

int PesPadding::get(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        st_id = var_bs.getbits(32);
        if (st_id != 446) {
            MG_ERROR(_T("Const value mismatch for 'st_id'"));
            var_ret++;
        }
        var_id_parsed = 1;
    }
    var_ret += PesBase::get(var_bs);
    for (i=0; i<PES_packet_length; i++) {
        padding_byte = var_bs.getbits(8);
        if (padding_byte != 255) {
            MG_ERROR(_T("Const value mismatch for 'padding_byte'"));
            var_ret++;
        }
    }
    return var_ret;
}

int PesPadding::put(IBitstream &var_bs, int var_id_parsed) {
    int var_ret = 0;
    int var_parse = 0;
    if (var_id_parsed == 0) {
        var_parse = 32;
        st_id = 446;
        var_bs.putbits(st_id, var_parse);
        var_id_parsed = 1;
    }
    var_ret += PesBase::put(var_bs);
    for (i=0; i<PES_packet_length; i++) {
        var_parse = 8;
        padding_byte = 255;
        var_bs.putbits(padding_byte, var_parse);
    }
    return var_ret;
}

int Adaptation_Field::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    adaptation_field_length = var_bs.getbits(8);
    if (adaptation_field_length>0&&adaptation_field_length<=183)
    {
        discontinuity_indicator = var_bs.getbits(1);
        random_access_indicator = var_bs.getbits(1);
        elementary_stream_priority_indicator = var_bs.getbits(1);
        PCR_flag = var_bs.getbits(1);
        OPCR_flag = var_bs.getbits(1);
        splicing_point_flag = var_bs.getbits(1);
        transport_private_data_flag = var_bs.getbits(1);
        adaptation_field_extension_flag = var_bs.getbits(1);
        unsigned int total_bits;
        total_bits = 8;
        if (PCR_flag==1)
        {
            program_clock_ref_1 = var_bs.getbits(3);
            program_clock_ref_2 = var_bs.getbits(15);
            program_clock_ref_3 = var_bs.getbits(15);
            reserved = var_bs.getbits(6);
            program_clock_reference_extension = var_bs.getbits(9);
            total_bits+=48;
        }
        
        if (OPCR_flag==1)
        {
            original_program_clock_ref_1 = var_bs.getbits(3);
            original_program_clock_ref_2 = var_bs.getbits(15);
            original_program_clock_ref_3 = var_bs.getbits(15);
            original_reserved = var_bs.getbits(6);
            original_program_clock_reference_extension = var_bs.getbits(9);
            total_bits+=48;
        }
        
        if (splicing_point_flag==1)
        {
            splice_countdown = var_bs.getbits(8);
            total_bits+=8;
        }
        
        if (transport_private_data_flag==1)
        {
            transport_private_data_length = var_bs.getbits(8);
            unsigned int i;
            i = 0;
            for (i=0; i<transport_private_data_length; i++) {
                var_dim0 = i;
                private_data_byte[var_dim0] = var_bs.getbits(8);
            }
            total_bits+=transport_private_data_length*8;
        }
        
        if (adaptation_field_extension_flag==1)
        {
            adaptation_field_extension_length = var_bs.getbits(8);
            total_bits+=adaptation_field_extension_length/8;
            
                    var_bs.skipbits(adaptation_field_extension_length * 8);
            
        }
        
        if ((total_bits/8)<adaptation_field_length)
        {
            
                    var_bs.skipbits((adaptation_field_length*8) - total_bits);
            
        }
        
    }
    
    return var_ret;
}

int Adaptation_Field::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.putbits(adaptation_field_length, 8);
    if (adaptation_field_length>0&&adaptation_field_length<=183)
    {
        var_bs.putbits(discontinuity_indicator, 1);
        var_bs.putbits(random_access_indicator, 1);
        var_bs.putbits(elementary_stream_priority_indicator, 1);
        var_bs.putbits(PCR_flag, 1);
        var_bs.putbits(OPCR_flag, 1);
        var_bs.putbits(splicing_point_flag, 1);
        var_bs.putbits(transport_private_data_flag, 1);
        var_bs.putbits(adaptation_field_extension_flag, 1);
        unsigned int total_bits;
        total_bits = 8;
        if (PCR_flag==1)
        {
            var_bs.putbits(program_clock_ref_1, 3);
            var_bs.putbits(program_clock_ref_2, 15);
            var_bs.putbits(program_clock_ref_3, 15);
            var_bs.putbits(reserved, 6);
            var_bs.putbits(program_clock_reference_extension, 9);
            total_bits+=48;
        }
        
        if (OPCR_flag==1)
        {
            var_bs.putbits(original_program_clock_ref_1, 3);
            var_bs.putbits(original_program_clock_ref_2, 15);
            var_bs.putbits(original_program_clock_ref_3, 15);
            var_bs.putbits(original_reserved, 6);
            var_bs.putbits(original_program_clock_reference_extension, 9);
            total_bits+=48;
        }
        
        if (splicing_point_flag==1)
        {
            var_bs.putbits(splice_countdown, 8);
            total_bits+=8;
        }
        
        if (transport_private_data_flag==1)
        {
            var_bs.putbits(transport_private_data_length, 8);
            unsigned int i;
            i = 0;
            for (i=0; i<transport_private_data_length; i++) {
                var_dim0 = i;
                var_bs.putbits(private_data_byte[var_dim0], 8);
            }
            total_bits+=transport_private_data_length*8;
        }
        
        if (adaptation_field_extension_flag==1)
        {
            var_bs.putbits(adaptation_field_extension_length, 8);
            total_bits+=adaptation_field_extension_length/8;
            
               for(unsigned int dx = 0; dx < adaptation_field_extension_length; dx++)
                    var_bs.putbits(0x0, 8);
            
        }
        
        if ((total_bits/8)<adaptation_field_length)
        {
            
               for(unsigned int dx = 0; dx < (adaptation_field_length - (total_bits/8)); dx++)
                    var_bs.putbits(0x0, 8);
            
        }
        
    }
    
    return var_ret;
}

int Pointer_Field::get(IBitstream &var_bs) {
    int var_ret = 0;
    pointer_field = var_bs.getbits(8);
    
       var_bs.skipbits(pointer_field * 8);
    
    return var_ret;
}

int Pointer_Field::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.putbits(pointer_field, 8);
    
       for(unsigned int dx = 0; dx < pointer_field; dx++)
            var_bs.putbits(0x0, 8);
    
    return var_ret;
}

int BaseSection::get(IBitstream &var_bs) {
    int var_ret = 0;
    table_id = var_bs.getbits(8);
    section_syntax_indicator = var_bs.getbits(1);
    if (section_syntax_indicator != 1) {
        MG_ERROR(_T("Const value mismatch for 'section_syntax_indicator'"));
        var_ret++;
    }
    marker = var_bs.getbits(1);
    reserved = var_bs.getbits(2);
    section_length = var_bs.getbits(12);
    id = var_bs.getbits(16);
    reserved2 = var_bs.getbits(2);
    version_number = var_bs.getbits(5);
    current_next_indicator = var_bs.getbits(1);
    section_number = var_bs.getbits(8);
    last_section_number = var_bs.getbits(8);
    return var_ret;
}

int BaseSection::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.putbits(table_id, 8);
    var_parse = 1;
    section_syntax_indicator = 1;
    var_bs.putbits(section_syntax_indicator, var_parse);
    var_bs.putbits(marker, 1);
    var_bs.putbits(reserved, 2);
    var_bs.putbits(section_length, 12);
    var_bs.putbits(id, 16);
    var_bs.putbits(reserved2, 2);
    var_bs.putbits(version_number, 5);
    var_bs.putbits(current_next_indicator, 1);
    var_bs.putbits(section_number, 8);
    var_bs.putbits(last_section_number, 8);
    return var_ret;
}

int Program_Association_Section::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_ret += BaseSection::get(var_bs);
    i = 0;
    for (i=0; i<((section_length-(9))/4); i++) {
        var_dim0 = i;
        program_number[var_dim0] = var_bs.getbits(16);
        reserved3 = var_bs.getbits(3);
        if (program_number[i]==0)
        {
            network_PID = var_bs.getbits(13);
        }
        else
        {
            var_dim0 = i;
            program_map_PID[var_dim0] = var_bs.getbits(13);
        }
        
    }
    CRC_32 = var_bs.getbits(32);
    return var_ret;
}

int Program_Association_Section::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_ret += BaseSection::put(var_bs);
    i = 0;
    for (i=0; i<((section_length-(9))/4); i++) {
        var_dim0 = i;
        var_bs.putbits(program_number[var_dim0], 16);
        var_bs.putbits(reserved3, 3);
        if (program_number[i]==0)
        {
            var_bs.putbits(network_PID, 13);
        }
        else
        {
            var_dim0 = i;
            var_bs.putbits(program_map_PID[var_dim0], 13);
        }
        
    }
    var_bs.putbits(CRC_32, 32);
    return var_ret;
}

int Program_Map_Section::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_ret += BaseSection::get(var_bs);
    reserved3 = var_bs.getbits(3);
    PCR_PID = var_bs.getbits(13);
    reserved4 = var_bs.getbits(4);
    program_info_length = var_bs.getbits(12);
    des_byte_count = 0;
    for (des_byte_count=0; des_byte_count<program_info_length; ) {
        descriptor = new(base_program_descriptor);
        var_ret += descriptor->get(var_bs);
        
			_program_descriptor.push_back(descriptor);
			des_byte_count += (descriptor->length + 2);
	   
    }
    program_byte_count = 0;
    stream_count = 0;
    for (program_byte_count=0; program_byte_count<(section_length-(13)-program_info_length); program_byte_count) {
        var_dim0 = stream_count;
        stream_type[var_dim0] = var_bs.getbits(8);
        reserved5 = var_bs.getbits(3);
        var_dim0 = stream_count;
        elementary_PID[var_dim0] = var_bs.getbits(13);
        reserved6 = var_bs.getbits(4);
        ES_info_length = var_bs.getbits(12);
        unsigned int stream_info_descriptor;
        stream_info_descriptor = 0;
        
				_stream_descriptors.push_back(new std::vector<base_program_descriptor*>);
		
        for (stream_info_descriptor=0; stream_info_descriptor<ES_info_length; stream_info_descriptor) {
            descriptor = new(base_program_descriptor);
            var_ret += descriptor->get(var_bs);
            
				
					
				_stream_descriptors[stream_count]->push_back(descriptor);
				stream_info_descriptor += (descriptor->length + 2);
			
        }
        program_byte_count+=(5+ES_info_length);
        stream_count++;
    }
    CRC_32 = var_bs.getbits(32);
    return var_ret;
}

int Program_Map_Section::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_ret += BaseSection::put(var_bs);
    var_bs.putbits(reserved3, 3);
    var_bs.putbits(PCR_PID, 13);
    var_bs.putbits(reserved4, 4);
    var_bs.putbits(program_info_length, 12);
    des_byte_count = 0;
     
	    int descriptor_count = 0;
	
    for (des_byte_count=0; des_byte_count<program_info_length; ) {
        
		   descriptor      = _program_descriptor[descriptor_count++];
		   des_byte_count += (descriptor->length + 2);
	   
        var_ret += descriptor->put(var_bs);
    }
    program_byte_count = 0;
    stream_count = 0;
    for (program_byte_count=0; program_byte_count<(section_length-(13)-program_info_length); program_byte_count) {
        var_dim0 = stream_count;
        var_bs.putbits(stream_type[var_dim0], 8);
        var_bs.putbits(reserved5, 3);
        var_dim0 = stream_count;
        var_bs.putbits(elementary_PID[var_dim0], 13);
        var_bs.putbits(reserved6, 4);
        var_bs.putbits(ES_info_length, 12);
        unsigned int stream_info_descriptor;
        stream_info_descriptor = 0;
         
			unsigned int stream_descriptor_count = 0;
		
        for (stream_info_descriptor=0; stream_info_descriptor<ES_info_length; stream_info_descriptor) {
            
				descriptor      = (*_stream_descriptors[stream_count])[stream_descriptor_count++];
				stream_info_descriptor += (descriptor->length + 2);
			
            var_ret += descriptor->put(var_bs);
        }
        program_byte_count+=(5+ES_info_length);
        stream_count++;
    }
    var_bs.putbits(CRC_32, 32);
    return var_ret;
}

int Transport_Packet::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    
       CleanUp();
       var_bs.nextcode(0x47, 8, 8);
       var_bs.skipbits(8);
    
    transport_error_indicator = var_bs.getbits(1);
    if (!transport_error_indicator)
    {
        payload_unit_start_indicator = var_bs.getbits(1);
        transport_priority = var_bs.getbits(1);
        PID = var_bs.getbits(13);
        transport_scrambling_control = var_bs.getbits(2);
        adaptation_flag = var_bs.getbits(1);
        payload_field = var_bs.getbits(1);
        continuity_counter = var_bs.getbits(4);
        if (adaptation_flag==1)
        {
            adaptation_field = new(Adaptation_Field);
            var_ret += adaptation_field->get(var_bs);
            if (payload_field==1&&adaptation_field->adaptation_field_length<=183)
            {
                unsigned int i;
                i = 0;
                for (i=0; i<(183-adaptation_field->adaptation_field_length); i++) {
                    var_dim0 = i;
                    payload_after_adaptation_byte[var_dim0] = var_bs.getbits(8);
                }
            }
            
        }
        else
        {
            if (payload_field==1)
            {
                int i;
                i = 0;
                for (i=0; i<184; i++) {
                    var_dim0 = i;
                    payload_byte[var_dim0] = var_bs.getbits(8);
                }
            }
            
        }
        
    }
    
    _packet_count++;
    return var_ret;
}

int Transport_Packet::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    
       var_bs.putbits(0x47, 8);
    
    var_bs.putbits(transport_error_indicator, 1);
    if (!transport_error_indicator)
    {
        var_bs.putbits(payload_unit_start_indicator, 1);
        var_bs.putbits(transport_priority, 1);
        var_bs.putbits(PID, 13);
        var_bs.putbits(transport_scrambling_control, 2);
        var_bs.putbits(adaptation_flag, 1);
        var_bs.putbits(payload_field, 1);
        var_bs.putbits(continuity_counter, 4);
        if (adaptation_flag==1)
        {
            var_ret += adaptation_field->put(var_bs);
            if (payload_field==1&&adaptation_field->adaptation_field_length<=183)
            {
                unsigned int i;
                i = 0;
                for (i=0; i<(183-adaptation_field->adaptation_field_length); i++) {
                    var_dim0 = i;
                    var_bs.putbits(payload_after_adaptation_byte[var_dim0], 8);
                }
            }
            
        }
        else
        {
            if (payload_field==1)
            {
                int i;
                i = 0;
                for (i=0; i<184; i++) {
                    var_dim0 = i;
                    var_bs.putbits(payload_byte[var_dim0], 8);
                }
            }
            
        }
        
    }
    
    return var_ret;
}

int SequenceExtension::get(IBitstream &var_bs) {
    int var_ret = 0;
    extension_start_code = var_bs.getbits(32);
    if (extension_start_code != 437) {
        MG_ERROR(_T("Const value mismatch for 'extension_start_code'"));
        var_ret++;
    }
    extension_start_code_identifier = var_bs.getbits(4);
    if (extension_start_code_identifier != 1) {
        MG_ERROR(_T("Const value mismatch for 'extension_start_code_identifier'"));
        var_ret++;
    }
    profile_and_level_indication = var_bs.getbits(8);
    progressive_sequence = var_bs.getbits(1);
    chroma_format = var_bs.getbits(2);
    horizontal_size_extension = var_bs.getbits(2);
    vertical_size_extension = var_bs.getbits(2);
    bit_rate_extension = var_bs.getbits(12);
    marker_bit = var_bs.getbits(1);
    vbv_buffer_size_extension = var_bs.getbits(8);
    low_delay = var_bs.getbits(1);
    frame_rate_extension_n = var_bs.getbits(2);
    frame_rate_extension_d = var_bs.getbits(5);
    return var_ret;
}

int SequenceExtension::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 32;
    extension_start_code = 437;
    var_bs.putbits(extension_start_code, var_parse);
    var_parse = 4;
    extension_start_code_identifier = 1;
    var_bs.putbits(extension_start_code_identifier, var_parse);
    var_bs.putbits(profile_and_level_indication, 8);
    var_bs.putbits(progressive_sequence, 1);
    var_bs.putbits(chroma_format, 2);
    var_bs.putbits(horizontal_size_extension, 2);
    var_bs.putbits(vertical_size_extension, 2);
    var_bs.putbits(bit_rate_extension, 12);
    var_bs.putbits(marker_bit, 1);
    var_bs.putbits(vbv_buffer_size_extension, 8);
    var_bs.putbits(low_delay, 1);
    var_bs.putbits(frame_rate_extension_n, 2);
    var_bs.putbits(frame_rate_extension_d, 5);
    return var_ret;
}

int SequenceHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end;
    packet_start_code_prefix = var_bs.getbits(24);
    if (packet_start_code_prefix != 1) {
        MG_ERROR(_T("Const value mismatch for 'packet_start_code_prefix'"));
        var_ret++;
    }
    stream_id = var_bs.getbits(8);
    if (stream_id != 179) {
        MG_ERROR(_T("Const value mismatch for 'stream_id'"));
        var_ret++;
    }
    horizontal_size_value = var_bs.getbits(12);
    vertical_size_value = var_bs.getbits(12);
    aspect_ratio_information = var_bs.getbits(4);
    frame_rate_code = var_bs.getbits(4);
    bit_rate_value = var_bs.getbits(18);
    marker_bit = var_bs.getbits(1);
    if (marker_bit != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
        var_ret++;
    }
    vbv_buffer_size_value = var_bs.getbits(10);
    constrained_parameters_flag = var_bs.getbits(1);
    load_intra_quantiser_matrix = var_bs.getbits(1);
    if (1==load_intra_quantiser_matrix)
    {
        var_dim0_end = 64;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            intra_quantiser_matrix[var_dim0] = var_bs.sgetbits(8);
        }
    }
    
    load_non_intra_quantiser_matrix = var_bs.getbits(1);
    if (1==load_non_intra_quantiser_matrix)
    {
        var_dim0_end = 64;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            non_intra_quantiser_matrix[var_dim0] = var_bs.sgetbits(8);
        }
    }
    
    if (var_bs.next(32, 1, 0, 0)==437)
    {
        sequenceextension = new(SequenceExtension);
        var_ret += sequenceextension->get(var_bs);
    }
    
    return var_ret;
}

int SequenceHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end;
    int var_parse = 0;
    var_parse = 24;
    packet_start_code_prefix = 1;
    var_bs.putbits(packet_start_code_prefix, var_parse);
    var_parse = 8;
    stream_id = 179;
    var_bs.putbits(stream_id, var_parse);
    var_bs.putbits(horizontal_size_value, 12);
    var_bs.putbits(vertical_size_value, 12);
    var_bs.putbits(aspect_ratio_information, 4);
    var_bs.putbits(frame_rate_code, 4);
    var_bs.putbits(bit_rate_value, 18);
    var_parse = 1;
    marker_bit = 1;
    var_bs.putbits(marker_bit, var_parse);
    var_bs.putbits(vbv_buffer_size_value, 10);
    var_bs.putbits(constrained_parameters_flag, 1);
    var_bs.putbits(load_intra_quantiser_matrix, 1);
    if (1==load_intra_quantiser_matrix)
    {
        var_dim0_end = 64;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            var_bs.putbits(intra_quantiser_matrix[var_dim0], 8);
        }
    }
    
    var_bs.putbits(load_non_intra_quantiser_matrix, 1);
    if (1==load_non_intra_quantiser_matrix)
    {
        var_dim0_end = 64;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            var_bs.putbits(non_intra_quantiser_matrix[var_dim0], 8);
        }
    }
    
    if (var_bs.next(32, 1, 0, 0)==437)
    {
        var_ret += sequenceextension->put(var_bs);
    }
    
    return var_ret;
}

int MpegHeaderInfo::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.nextcode(0x1, 24, 8);
    return var_ret;
}

int MpegHeaderInfo::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.nextcode(0x1, 24, 8);
    return var_ret;
}

int PitcureBase::get(IBitstream &var_bs) {
    int var_ret = 0;
    picture_start_code = var_bs.getbits(32);
    if (picture_start_code != 256) {
        MG_ERROR(_T("Const value mismatch for 'picture_start_code'"));
        var_ret++;
    }
    temporal_reference = var_bs.getbits(10);
    picture_coding_type = var_bs.getbits(3);
    vbv_delay = var_bs.getbits(16);
    return var_ret;
}

int PitcureBase::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 32;
    picture_start_code = 256;
    var_bs.putbits(picture_start_code, var_parse);
    var_bs.putbits(temporal_reference, 10);
    var_bs.putbits(picture_coding_type, 3);
    var_bs.putbits(vbv_delay, 16);
    return var_ret;
}

int PitcureInfo::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PitcureBase::get(var_bs);
    garbage = var_bs.getbits(3);
    return var_ret;
}

int PitcureInfo::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PitcureBase::put(var_bs);
    var_bs.putbits(garbage, 3);
    return var_ret;
}

int Picture_Coding_Extension::get(IBitstream &var_bs) {
    int var_ret = 0;
    extension_start_code = var_bs.getbits(32);
    if (extension_start_code != 437) {
        MG_ERROR(_T("Const value mismatch for 'extension_start_code'"));
        var_ret++;
    }
    extension_start_code_identifier = var_bs.getbits(4);
    if (extension_start_code_identifier != 8) {
        MG_ERROR(_T("Const value mismatch for 'extension_start_code_identifier'"));
        var_ret++;
    }
    f_code1 = var_bs.getbits(4);
    f_code2 = var_bs.getbits(4);
    f_code3 = var_bs.getbits(4);
    f_code4 = var_bs.getbits(4);
    intra_dc_precision = var_bs.getbits(2);
    picture_structure = var_bs.getbits(2);
    top_field_first = var_bs.getbits(1);
    frame_pred_frame_dct = var_bs.getbits(1);
    concealment_motion_vectors = var_bs.getbits(1);
    q_scale_type = var_bs.getbits(1);
    intra_vlc_format = var_bs.getbits(1);
    alternate_scan = var_bs.getbits(1);
    repeat_first_field = var_bs.getbits(1);
    chroma_420_type = var_bs.getbits(1);
    progressive_frame = var_bs.getbits(1);
    composite_display_flag = var_bs.getbits(1);
    if (composite_display_flag)
    {
        v_axis = var_bs.getbits(1);
        field_sequence = var_bs.getbits(3);
        sub_carrier = var_bs.getbits(1);
        burst_amplitude = var_bs.getbits(7);
        sub_carrier_phase = var_bs.getbits(8);
        var_bs.skipbits(2);
    }
    else
    {
        var_bs.skipbits(6);
    }
    
    return var_ret;
}

int Picture_Coding_Extension::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 32;
    extension_start_code = 437;
    var_bs.putbits(extension_start_code, var_parse);
    var_parse = 4;
    extension_start_code_identifier = 8;
    var_bs.putbits(extension_start_code_identifier, var_parse);
    var_bs.putbits(f_code1, 4);
    var_bs.putbits(f_code2, 4);
    var_bs.putbits(f_code3, 4);
    var_bs.putbits(f_code4, 4);
    var_bs.putbits(intra_dc_precision, 2);
    var_bs.putbits(picture_structure, 2);
    var_bs.putbits(top_field_first, 1);
    var_bs.putbits(frame_pred_frame_dct, 1);
    var_bs.putbits(concealment_motion_vectors, 1);
    var_bs.putbits(q_scale_type, 1);
    var_bs.putbits(intra_vlc_format, 1);
    var_bs.putbits(alternate_scan, 1);
    var_bs.putbits(repeat_first_field, 1);
    var_bs.putbits(chroma_420_type, 1);
    var_bs.putbits(progressive_frame, 1);
    var_bs.putbits(composite_display_flag, 1);
    if (composite_display_flag)
    {
        var_bs.putbits(v_axis, 1);
        var_bs.putbits(field_sequence, 3);
        var_bs.putbits(sub_carrier, 1);
        var_bs.putbits(burst_amplitude, 7);
        var_bs.putbits(sub_carrier_phase, 8);
        var_bs.skipbits(2);
    }
    else
    {
        var_bs.skipbits(6);
    }
    
    return var_ret;
}

int PitcureHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PitcureBase::get(var_bs);
    x = 29;
    if (picture_coding_type==2||picture_coding_type==3)
    {
        full_pel_forward_vector = var_bs.getbits(1);
        forward_f_code = var_bs.getbits(3);
        x+=4;
    }
    
    if (picture_coding_type==3)
    {
        full_pel_backward_vector = var_bs.getbits(1);
        backward_f_code = var_bs.getbits(3);
        x+=4;
    }
    
    extra_bit_picture = var_bs.getbits(1);
    x+=1;
    while (extra_bit_picture==1) {
        extra_information_picture = var_bs.getbits(8);
        extra_bit_picture = var_bs.getbits(1);
        x+=9;
    }
    var_bs.skipbits(8-(x%8));
    if (var_bs.next(32, 1, 0, 0)==437)
    {
        pictureextension = new(Picture_Coding_Extension);
        var_ret += pictureextension->get(var_bs);
    }
    
    return var_ret;
}

int PitcureHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_ret += PitcureBase::put(var_bs);
    x = 29;
    if (picture_coding_type==2||picture_coding_type==3)
    {
        var_bs.putbits(full_pel_forward_vector, 1);
        var_bs.putbits(forward_f_code, 3);
        x+=4;
    }
    
    if (picture_coding_type==3)
    {
        var_bs.putbits(full_pel_backward_vector, 1);
        var_bs.putbits(backward_f_code, 3);
        x+=4;
    }
    
    var_bs.putbits(extra_bit_picture, 1);
    x+=1;
    while (extra_bit_picture==1) {
        var_bs.putbits(extra_information_picture, 8);
        var_bs.putbits(extra_bit_picture, 1);
        x+=9;
    }
    var_bs.skipbits(8-(x%8));
    if (var_bs.next(32, 1, 0, 0)==437)
    {
        var_ret += pictureextension->put(var_bs);
    }
    
    return var_ret;
}

int GroupOfPictureHeader::get(IBitstream &var_bs) {
    int var_ret = 0;
    gop_start_code = var_bs.getbits(32);
    if (gop_start_code != 440) {
        MG_ERROR(_T("Const value mismatch for 'gop_start_code'"));
        var_ret++;
    }
    drop_frame_flag = var_bs.getbits(1);
    time_code_hours = var_bs.getbits(5);
    time_code_minutes = var_bs.getbits(6);
    marker_bit = var_bs.getbits(1);
    if (marker_bit != 1) {
        MG_ERROR(_T("Const value mismatch for 'marker_bit'"));
        var_ret++;
    }
    time_code_seconds = var_bs.getbits(6);
    time_code_pictures = var_bs.getbits(6);
    closed_gop = var_bs.getbits(1);
    broken_link = var_bs.getbits(1);
    filler = var_bs.getbits(5);
    if (filler != 0) {
        MG_ERROR(_T("Const value mismatch for 'filler'"));
        var_ret++;
    }
    return var_ret;
}

int GroupOfPictureHeader::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_parse = 32;
    gop_start_code = 440;
    var_bs.putbits(gop_start_code, var_parse);
    var_bs.putbits(drop_frame_flag, 1);
    var_bs.putbits(time_code_hours, 5);
    var_bs.putbits(time_code_minutes, 6);
    var_parse = 1;
    marker_bit = 1;
    var_bs.putbits(marker_bit, var_parse);
    var_bs.putbits(time_code_seconds, 6);
    var_bs.putbits(time_code_pictures, 6);
    var_bs.putbits(closed_gop, 1);
    var_bs.putbits(broken_link, 1);
    var_parse = 5;
    filler = 0;
    var_bs.putbits(filler, var_parse);
    return var_ret;
}

__ALX_END_NAMESPACE
