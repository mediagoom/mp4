/* @mediagen - output in case of error -
 *
 * h264.cpp
 * 
 * This file was automatically generated
 * from the source file:
 *     'h264.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#include "stdafx.h"
#include <TBitstream.h>
#include "h264.h"


__ALX_BEGIN_NAMESPACE

int hrd_parameters::get(IBitstream &var_bs) {
    int var_ret = 0;
    cpb_cnt_minus1 = 0;
    cpb_cnt_minus1  = exp_ue_golomb(var_bs);
    bit_rate_scale = var_bs.getbits(4);
    cpb_size_scale = var_bs.getbits(4);
    SchedSelIdx = 0;
    for (SchedSelIdx=0; SchedSelIdx<=cpb_cnt_minus1; SchedSelIdx++) {
        bit_rate_value_minus1[ SchedSelIdx ]  = exp_ue_golomb(var_bs);
        cpb_size_value_minus1[ SchedSelIdx ]  = exp_ue_golomb(var_bs);
        cbr_flag = var_bs.getbits(1);
    }
    initial_cpb_removal_delay_length_minus1 = var_bs.getbits(5);
    cpb_removal_delay_length_minus1 = var_bs.getbits(5);
    dpb_output_delay_length_minus1 = var_bs.getbits(5);
    time_offset_length = var_bs.getbits(5);
    return var_ret;
}

int hrd_parameters::put(IBitstream &var_bs) {
    int var_ret = 0;
    cpb_cnt_minus1 = 0;
    var_bs.putbits(bit_rate_scale, 4);
    var_bs.putbits(cpb_size_scale, 4);
    SchedSelIdx = 0;
    for (SchedSelIdx=0; SchedSelIdx<=cpb_cnt_minus1; SchedSelIdx++) {
        var_bs.putbits(cbr_flag, 1);
    }
    var_bs.putbits(initial_cpb_removal_delay_length_minus1, 5);
    var_bs.putbits(cpb_removal_delay_length_minus1, 5);
    var_bs.putbits(dpb_output_delay_length_minus1, 5);
    var_bs.putbits(time_offset_length, 5);
    return var_ret;
}

int vui_parameters::get(IBitstream &var_bs) {
    int var_ret = 0;
    chroma_sample_loc_type_top_field = 0;
    chroma_sample_loc_type_bottom_field = 0;
    max_bytes_per_pic_denom = 0;
    max_bits_per_mb_denom = 0;
    log2_max_mv_length_horizontal = 0;
    log2_max_mv_length_vertical = 0;
    num_reorder_frames = 0;
    max_dec_frame_buffering = 0;
    aspect_ratio_info_present_flag = var_bs.getbits(1);
    if (aspect_ratio_info_present_flag)
    {
        aspect_ratio_idc = var_bs.getbits(8);
        if (aspect_ratio_idc==255)
        {
            sar_width = var_bs.getbits(16);
            sar_height = var_bs.getbits(16);
        }
        
    }
    
    overscan_info_present_flag = var_bs.getbits(1);
    if (overscan_info_present_flag) {
        overscan_appropriate_flag = var_bs.getbits(1);
    }
    
    video_signal_type_present_flag = var_bs.getbits(1);
    if (video_signal_type_present_flag)
    {
        video_format = var_bs.getbits(3);
        video_full_range_flag = var_bs.getbits(1);
        colour_description_present_flag = var_bs.getbits(1);
        if (colour_description_present_flag)
        {
            colour_primaries = var_bs.getbits(8);
            transfer_characteristics = var_bs.getbits(8);
            matrix_coefficients = var_bs.getbits(8);
        }
        
    }
    
    chroma_loc_info_present_flag = var_bs.getbits(1);
    if (chroma_loc_info_present_flag)
    {
        chroma_sample_loc_type_top_field  = exp_ue_golomb(var_bs);
        chroma_sample_loc_type_bottom_field  = exp_ue_golomb(var_bs);
    }
    
    timing_info_present_flag = var_bs.getbits(1);
    if (timing_info_present_flag)
    {
        num_units_in_tick = var_bs.getbits(32);
        time_scale = var_bs.getbits(32);
        fixed_frame_rate_flag = var_bs.getbits(1);
    }
    
    nal_hrd_parameters_present_flag = var_bs.getbits(1);
    if (nal_hrd_parameters_present_flag) {
        HRD = new(hrd_parameters);
        var_ret += HRD->get(var_bs);
    }
    
    vcl_hrd_parameters_present_flag = var_bs.getbits(1);
    if (vcl_hrd_parameters_present_flag)
    {
        VLC_HRD = new(hrd_parameters);
        var_ret += VLC_HRD->get(var_bs);
    }
    
    if (nal_hrd_parameters_present_flag||vcl_hrd_parameters_present_flag) {
        low_delay_hrd_flag = var_bs.getbits(1);
    }
    
    pic_struct_present_flag = var_bs.getbits(1);
    bitstream_restriction_flag = var_bs.getbits(1);
    if (bitstream_restriction_flag)
    {
        motion_vectors_over_pic_boundaries_flag = var_bs.getbits(1);
        max_bytes_per_pic_denom  = exp_ue_golomb(var_bs);
        max_bits_per_mb_denom  = exp_ue_golomb(var_bs);
        log2_max_mv_length_horizontal  = exp_ue_golomb(var_bs);
        log2_max_mv_length_vertical  = exp_ue_golomb(var_bs);
        num_reorder_frames  = exp_ue_golomb(var_bs);
        max_dec_frame_buffering  = exp_ue_golomb(var_bs);
    }
    
    return var_ret;
}

int vui_parameters::put(IBitstream &var_bs) {
    int var_ret = 0;
    chroma_sample_loc_type_top_field = 0;
    chroma_sample_loc_type_bottom_field = 0;
    max_bytes_per_pic_denom = 0;
    max_bits_per_mb_denom = 0;
    log2_max_mv_length_horizontal = 0;
    log2_max_mv_length_vertical = 0;
    num_reorder_frames = 0;
    max_dec_frame_buffering = 0;
    var_bs.putbits(aspect_ratio_info_present_flag, 1);
    if (aspect_ratio_info_present_flag)
    {
        var_bs.putbits(aspect_ratio_idc, 8);
        if (aspect_ratio_idc==255)
        {
            var_bs.putbits(sar_width, 16);
            var_bs.putbits(sar_height, 16);
        }
        
    }
    
    var_bs.putbits(overscan_info_present_flag, 1);
    if (overscan_info_present_flag) {
        var_bs.putbits(overscan_appropriate_flag, 1);
    }
    
    var_bs.putbits(video_signal_type_present_flag, 1);
    if (video_signal_type_present_flag)
    {
        var_bs.putbits(video_format, 3);
        var_bs.putbits(video_full_range_flag, 1);
        var_bs.putbits(colour_description_present_flag, 1);
        if (colour_description_present_flag)
        {
            var_bs.putbits(colour_primaries, 8);
            var_bs.putbits(transfer_characteristics, 8);
            var_bs.putbits(matrix_coefficients, 8);
        }
        
    }
    
    var_bs.putbits(chroma_loc_info_present_flag, 1);
    if (chroma_loc_info_present_flag)
    {
    }
    
    var_bs.putbits(timing_info_present_flag, 1);
    if (timing_info_present_flag)
    {
        var_bs.putbits(num_units_in_tick, 32);
        var_bs.putbits(time_scale, 32);
        var_bs.putbits(fixed_frame_rate_flag, 1);
    }
    
    var_bs.putbits(nal_hrd_parameters_present_flag, 1);
    if (nal_hrd_parameters_present_flag) {
        var_ret += HRD->put(var_bs);
    }
    
    var_bs.putbits(vcl_hrd_parameters_present_flag, 1);
    if (vcl_hrd_parameters_present_flag)
    {
        var_ret += VLC_HRD->put(var_bs);
    }
    
    if (nal_hrd_parameters_present_flag||vcl_hrd_parameters_present_flag) {
        var_bs.putbits(low_delay_hrd_flag, 1);
    }
    
    var_bs.putbits(pic_struct_present_flag, 1);
    var_bs.putbits(bitstream_restriction_flag, 1);
    if (bitstream_restriction_flag)
    {
        var_bs.putbits(motion_vectors_over_pic_boundaries_flag, 1);
    }
    
    return var_ret;
}

int H264Sequence::get(IBitstream &var_bs) {
    int var_ret = 0;
    profile_idc = var_bs.getbits(8);
    constraint_set0_flag = var_bs.getbits(1);
    constraint_set1_flag = var_bs.getbits(1);
    constraint_set2_flag = var_bs.getbits(1);
    constraint_set3_flag = var_bs.getbits(1);
    reserved_zero_bits = var_bs.getbits(4);
    if (reserved_zero_bits != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved_zero_bits'"));
        var_ret++;
    }
    level_idc = var_bs.getbits(8);
    seq_parameter_set_id = exp_ue_golomb(var_bs);
    chroma_format_idc = 0;
    offset_for_non_ref_pic = 0;
    offset_for_top_to_bottom_field = 0;
    num_ref_frames_in_pic_order_cnt_cycle = 0;
    if (profile_idc>=100)
    {
        chroma_format_idc    = exp_ue_golomb(var_bs);
        if (chroma_format_idc==3)
        {
            residual_color_transform_flag = var_bs.getbits(1);
        }
        
        bit_depth_luma      = exp_ue_golomb(var_bs) ;
        bit_depth_chroma    = exp_ue_golomb(var_bs);
        transform_bypass = var_bs.getbits(1);
        decode_scaling_matrix = var_bs.getbits(1);
        if (decode_scaling_matrix != 0) {
            MG_ERROR(_T("Const value mismatch for 'decode_scaling_matrix'"));
            var_ret++;
        }
    }
    
    log2_max_frame_num_minus4 = exp_ue_golomb(var_bs) ;
    pic_order_cnt_type = 0;
    pic_order_cnt_type        = exp_ue_golomb(var_bs);
    if (pic_order_cnt_type==0)
    {
        log2_max_pic_order_cnt_lsb_minus4 = exp_ue_golomb(var_bs);
    }
    else {
        if (pic_order_cnt_type==1)
        {
            delta_pic_order_always_zero_flag = var_bs.getbits(1);
            offset_for_non_ref_pic = exp_se_golomb(var_bs);
            offset_for_top_to_bottom_field = exp_se_golomb(var_bs);
            num_ref_frames_in_pic_order_cnt_cycle = exp_ue_golomb(var_bs);
            unsigned int __i;
            __i = 0;
            for (__i=0; __i<num_ref_frames_in_pic_order_cnt_cycle; __i++) {
                unsigned int offset_for_ref_frame;
                
	     offset_for_ref_frame = exp_se_golomb(var_bs);
	     
            }
        }
        
    }
    
    num_ref_frames = exp_ue_golomb(var_bs);
    gaps_in_frame_num_value_allowed_flag = var_bs.getbits(1);
    pic_width_in_mbs_minus1 = exp_ue_golomb(var_bs);
    pic_height_in_map_units_minus1 = exp_ue_golomb(var_bs);
    frame_mbs_only_flag = var_bs.getbits(1);
    if (!frame_mbs_only_flag) {
        mb_adaptive_frame_field_flag = var_bs.getbits(1);
    }
    
    direct_8x8_inference_flag = var_bs.getbits(1);
    frame_cropping_flag = var_bs.getbits(1);
    if (frame_cropping_flag)
    {
        frame_crop_left_offset   = exp_ue_golomb(var_bs);
        frame_crop_right_offset  = exp_ue_golomb(var_bs);
        frame_crop_top_offset    = exp_ue_golomb(var_bs);
        frame_crop_bottom_offset = exp_ue_golomb(var_bs);
    }
    
    vui_parameters_present_flag = var_bs.getbits(1);
    if (vui_parameters_present_flag)
    {
        VUI = new(vui_parameters);
        var_ret += VUI->get(var_bs);
    }
    
    rbsp_stop_one_bit = var_bs.getbits(1);
    if (rbsp_stop_one_bit != 1) {
        MG_ERROR(_T("Const value mismatch for 'rbsp_stop_one_bit'"));
        var_ret++;
    }
    skip = var_bs.getpos()%8;
    if (skip)
    {
        var_bs.skipbits(8-skip);
    }
    
    return var_ret;
}

int H264Sequence::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.putbits(profile_idc, 8);
    var_bs.putbits(constraint_set0_flag, 1);
    var_bs.putbits(constraint_set1_flag, 1);
    var_bs.putbits(constraint_set2_flag, 1);
    var_bs.putbits(constraint_set3_flag, 1);
    var_parse = 4;
    reserved_zero_bits = 0;
    var_bs.putbits(reserved_zero_bits, var_parse);
    var_bs.putbits(level_idc, 8);
    chroma_format_idc = 0;
    offset_for_non_ref_pic = 0;
    offset_for_top_to_bottom_field = 0;
    num_ref_frames_in_pic_order_cnt_cycle = 0;
    if (profile_idc>=100)
    {
        if (chroma_format_idc==3)
        {
            var_bs.putbits(residual_color_transform_flag, 1);
        }
        
        var_bs.putbits(transform_bypass, 1);
        var_parse = 1;
        decode_scaling_matrix = 0;
        var_bs.putbits(decode_scaling_matrix, var_parse);
    }
    
    pic_order_cnt_type = 0;
    if (pic_order_cnt_type==0)
    {
    }
    else {
        if (pic_order_cnt_type==1)
        {
            var_bs.putbits(delta_pic_order_always_zero_flag, 1);
            unsigned int __i;
            __i = 0;
            for (__i=0; __i<num_ref_frames_in_pic_order_cnt_cycle; __i++) {
                unsigned int offset_for_ref_frame;
                
			 offset_for_ref_frame = 0;
		 
            }
        }
        
    }
    
    var_bs.putbits(gaps_in_frame_num_value_allowed_flag, 1);
    var_bs.putbits(frame_mbs_only_flag, 1);
    if (!frame_mbs_only_flag) {
        var_bs.putbits(mb_adaptive_frame_field_flag, 1);
    }
    
    var_bs.putbits(direct_8x8_inference_flag, 1);
    var_bs.putbits(frame_cropping_flag, 1);
    if (frame_cropping_flag)
    {
    }
    
    var_bs.putbits(vui_parameters_present_flag, 1);
    if (vui_parameters_present_flag)
    {
        var_ret += VUI->put(var_bs);
    }
    
    var_parse = 1;
    rbsp_stop_one_bit = 1;
    var_bs.putbits(rbsp_stop_one_bit, var_parse);
    skip = var_bs.getpos()%8;
    if (skip)
    {
        var_bs.skipbits(8-skip);
    }
    
    return var_ret;
}

int pic_parameter_set_rbsp::get(IBitstream &var_bs) {
    int var_ret = 0;
    pic_parameter_set_id = 0;
    seq_parameter_set_id = 0;
    num_slice_groups_minus1 = 0;
    slice_group_map_type = 0;
    slice_group_change_rate_minus1 = 0;
    pic_size_in_map_units_minus1 = 0;
    num_ref_idx_l0_active_minus1 = 0;
    num_ref_idx_l1_active_minus1 = 0;
    pic_init_qp_minus26 = 0;
    pic_init_qs_minus26 = 0;
    chroma_qp_index_offset = 0;
    second_chroma_qp_index_offset = 0;
    start_size = var_bs.getpos();
    pic_parameter_set_id  = exp_ue_golomb(var_bs);
    seq_parameter_set_id  = exp_ue_golomb(var_bs);
    entropy_coding_mode_flag = var_bs.getbits(1);
    pic_order_present_flag = var_bs.getbits(1);
    num_slice_groups_minus1  = exp_ue_golomb(var_bs);
    if (num_slice_groups_minus1>0)
    {
        slice_group_map_type  = exp_ue_golomb(var_bs);
        unsigned int iGroup;
        iGroup = 0;
        if (slice_group_map_type==0)
        {
            for (iGroup=0; iGroup<=num_slice_groups_minus1; iGroup++) {
                run_length_minus1[ iGroup ]  = exp_ue_golomb(var_bs);
            }
        }
        else {
            if (slice_group_map_type==2)
            {
                for (iGroup=0; iGroup<num_slice_groups_minus1; iGroup++) {
                    top_left[ iGroup ]  = exp_ue_golomb(var_bs);
                    bottom_right[ iGroup ]  = exp_ue_golomb(var_bs);
                }
            }
            else {
                if (slice_group_map_type==3||slice_group_map_type==4||slice_group_map_type==5)
                {
                    slice_group_change_direction_flag = var_bs.getbits(1);
                    slice_group_change_rate_minus1  = exp_ue_golomb(var_bs);
                }
                else {
                    if (slice_group_map_type==6)
                    {
                        pic_size_in_map_units_minus1  = exp_ue_golomb(var_bs);
                        unsigned int i;
                        i = 0;
                        for (i=0; i<=pic_size_in_map_units_minus1; i++) {
                            _ASSERTE(false);slice_group_id[ i ]  = exp_ue_golomb(var_bs);
                        }
                    }
                    
                }
                
            }
            
        }
        
    }
    
    num_ref_idx_l0_active_minus1  = exp_ue_golomb(var_bs);
    num_ref_idx_l1_active_minus1  = exp_ue_golomb(var_bs);
    weighted_pred_flag = var_bs.getbits(1);
    weighted_bipred_idc = var_bs.getbits(2);
    pic_init_qp_minus26  = exp_se_golomb(var_bs);
    pic_init_qs_minus26  = exp_se_golomb(var_bs);
    chroma_qp_index_offset  = exp_se_golomb(var_bs);
    deblocking_filter_control_present_flag = var_bs.getbits(1);
    constrained_intra_pred_flag = var_bs.getbits(1);
    redundant_pic_cnt_present_flag = var_bs.getbits(1);
    end_size = var_bs.getpos()+(var_bs.getpos()%8);
    extended = 0;
     if(_size && 
	             ( ( (end_size) - start_size) / 8) < _size
			) 
			extended = 1;
	
    if (extended)
    {
        transform_8x8_mode_flag = var_bs.getbits(1);
        pic_scaling_matrix_present_flag = var_bs.getbits(1);
        if (pic_scaling_matrix_present_flag)
        {
            unsigned int i;
            i = 0;
            unsigned int itime;
            itime = (6+2*transform_8x8_mode_flag);
            for (i=0; i<itime; i++) {
                pic_scaling_list_present_flag = var_bs.getbits(1);
                if (pic_scaling_list_present_flag)
                {
                    if (i<6)
                    {
                        
						  unsigned int j = 0;
						   for(j = 0; j < 16; j++)
						     exp_se_golomb(var_bs);
						
                    }
                    else
                    {
                        
						  unsigned int j = 0;
						   for(j = 0; j < 64; j++)
						     exp_se_golomb(var_bs);
						
                    }
                    
                }
                
            }
        }
        
        second_chroma_qp_index_offset  = exp_se_golomb(var_bs);
    }
    
    rbsp_stop_one_bit = var_bs.getbits(1);
    if (rbsp_stop_one_bit != 1) {
        MG_ERROR(_T("Const value mismatch for 'rbsp_stop_one_bit'"));
        var_ret++;
    }
    skip = var_bs.getpos()%8;
    if (skip)
    {
        var_bs.skipbits(8-skip);
    }
    
    return var_ret;
}

int pic_parameter_set_rbsp::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    pic_parameter_set_id = 0;
    seq_parameter_set_id = 0;
    num_slice_groups_minus1 = 0;
    slice_group_map_type = 0;
    slice_group_change_rate_minus1 = 0;
    pic_size_in_map_units_minus1 = 0;
    num_ref_idx_l0_active_minus1 = 0;
    num_ref_idx_l1_active_minus1 = 0;
    pic_init_qp_minus26 = 0;
    pic_init_qs_minus26 = 0;
    chroma_qp_index_offset = 0;
    second_chroma_qp_index_offset = 0;
    start_size = var_bs.getpos();
    var_bs.putbits(entropy_coding_mode_flag, 1);
    var_bs.putbits(pic_order_present_flag, 1);
    if (num_slice_groups_minus1>0)
    {
        unsigned int iGroup;
        iGroup = 0;
        if (slice_group_map_type==0)
        {
            for (iGroup=0; iGroup<=num_slice_groups_minus1; iGroup++) {
            }
        }
        else {
            if (slice_group_map_type==2)
            {
                for (iGroup=0; iGroup<num_slice_groups_minus1; iGroup++) {
                }
            }
            else {
                if (slice_group_map_type==3||slice_group_map_type==4||slice_group_map_type==5)
                {
                    var_bs.putbits(slice_group_change_direction_flag, 1);
                }
                else {
                    if (slice_group_map_type==6)
                    {
                        unsigned int i;
                        i = 0;
                        for (i=0; i<=pic_size_in_map_units_minus1; i++) {
                        }
                    }
                    
                }
                
            }
            
        }
        
    }
    
    var_bs.putbits(weighted_pred_flag, 1);
    var_bs.putbits(weighted_bipred_idc, 2);
    var_bs.putbits(deblocking_filter_control_present_flag, 1);
    var_bs.putbits(constrained_intra_pred_flag, 1);
    var_bs.putbits(redundant_pic_cnt_present_flag, 1);
    end_size = var_bs.getpos()+(var_bs.getpos()%8);
    extended = 0;
    if (extended)
    {
        var_bs.putbits(transform_8x8_mode_flag, 1);
        var_bs.putbits(pic_scaling_matrix_present_flag, 1);
        if (pic_scaling_matrix_present_flag)
        {
            unsigned int i;
            i = 0;
            unsigned int itime;
            itime = (6+2*transform_8x8_mode_flag);
            for (i=0; i<itime; i++) {
                var_bs.putbits(pic_scaling_list_present_flag, 1);
                if (pic_scaling_list_present_flag)
                {
                    if (i<6)
                    {
                    }
                    else
                    {
                    }
                    
                }
                
            }
        }
        
    }
    
    var_parse = 1;
    rbsp_stop_one_bit = 1;
    var_bs.putbits(rbsp_stop_one_bit, var_parse);
    skip = var_bs.getpos()%8;
    if (skip)
    {
        var_bs.skipbits(8-skip);
    }
    
    return var_ret;
}

int ref_pic_list_reordering::get(IBitstream &var_bs, unsigned int slice_type) {
    int var_ret = 0;
    t = 1;
    reordering_of_pic_nums_idc = 0;
    abs_diff_pic_num_minus1 = 0;
    long_term_pic_num = 0;
    if (slice_type!=2&&slice_type!=9)
    {
        ref_pic_list_reordering_flag_l0 = var_bs.getbits(1);
        if (ref_pic_list_reordering_flag_l0)
        {
            while (t) {
                reordering_of_pic_nums_idc = exp_ue_golomb(var_bs);
                if (reordering_of_pic_nums_idc==0||reordering_of_pic_nums_idc==1)
                {
                    abs_diff_pic_num_minus1  = exp_ue_golomb(var_bs);
                }
                else {
                    if (reordering_of_pic_nums_idc==2)
                    {
                        long_term_pic_num  = exp_ue_golomb(var_bs);
                    }
                    
                }
                
                if (reordering_of_pic_nums_idc==3) {
                    break;
                }
                
            }
        }
        
    }
    
    if (slice_type==1)
    {
        ref_pic_list_reordering_flag_l1 = var_bs.getbits(1);
        if (ref_pic_list_reordering_flag_l1) {
            while (t) {
                reordering_of_pic_nums_idc  = exp_ue_golomb(var_bs);
                if (reordering_of_pic_nums_idc==0||reordering_of_pic_nums_idc==1)
                {
                    abs_diff_pic_num_minus1  = exp_ue_golomb(var_bs);
                }
                else {
                    if (reordering_of_pic_nums_idc==2)
                    {
                        long_term_pic_num  = exp_ue_golomb(var_bs);
                    }
                    
                }
                
                if (reordering_of_pic_nums_idc==3) {
                    break;
                }
                
            }
        }
        
    }
    
    return var_ret;
}

int ref_pic_list_reordering::put(IBitstream &var_bs, unsigned int slice_type) {
    int var_ret = 0;
    t = 1;
    reordering_of_pic_nums_idc = 0;
    abs_diff_pic_num_minus1 = 0;
    long_term_pic_num = 0;
    if (slice_type!=2&&slice_type!=9)
    {
        var_bs.putbits(ref_pic_list_reordering_flag_l0, 1);
        if (ref_pic_list_reordering_flag_l0)
        {
            while (t) {
                if (reordering_of_pic_nums_idc==0||reordering_of_pic_nums_idc==1)
                {
                }
                else {
                    if (reordering_of_pic_nums_idc==2)
                    {
                    }
                    
                }
                
                if (reordering_of_pic_nums_idc==3) {
                    break;
                }
                
            }
        }
        
    }
    
    if (slice_type==1)
    {
        var_bs.putbits(ref_pic_list_reordering_flag_l1, 1);
        if (ref_pic_list_reordering_flag_l1) {
            while (t) {
                if (reordering_of_pic_nums_idc==0||reordering_of_pic_nums_idc==1)
                {
                }
                else {
                    if (reordering_of_pic_nums_idc==2)
                    {
                    }
                    
                }
                
                if (reordering_of_pic_nums_idc==3) {
                    break;
                }
                
            }
        }
        
    }
    
    return var_ret;
}

int pred_weight_table::get(IBitstream &var_bs, unsigned int num_ref_idx_l0_active_minus1, unsigned int num_ref_idx_l1_active_minus1, unsigned int slice_type) {
    int var_ret = 0;
    luma_log2_weight_denom = 0;
    chroma_log2_weight_denom = 0;
    i = 0;
    j = 0;
    luma_log2_weight_denom    = exp_ue_golomb(var_bs);
    chroma_log2_weight_denom  = exp_ue_golomb(var_bs);
    for (i=0; i<=num_ref_idx_l0_active_minus1; i++) {
        luma_weight_l0_flag = var_bs.getbits(1);
        if (luma_weight_l0_flag)
        {
            luma_weight_l0[ i ]  = exp_se_golomb(var_bs);
            luma_offset_l0[ i ]  = exp_se_golomb(var_bs);
        }
        
        chroma_weight_l0_flag = var_bs.getbits(1);
        if (chroma_weight_l0_flag) {
            for (j=0; j<2; j++) {
                chroma_weight_l0[ j ]  = exp_se_golomb(var_bs);
                chroma_offset_l0[ j ]  = exp_se_golomb(var_bs);
            }
        }
        
    }
    if (slice_type==1) {
        for (i=0; i<=num_ref_idx_l1_active_minus1; i++) {
            luma_weight_l1_flag = var_bs.getbits(1);
            if (luma_weight_l1_flag)
            {
                luma_weight_l1[ i ]  = exp_se_golomb(var_bs);
                luma_offset_l1[ i ]  = exp_se_golomb(var_bs);
            }
            
            chroma_weight_l1_flag = var_bs.getbits(1);
            if (chroma_weight_l1_flag) {
                for (j=0; j<2; j++) {
                    chroma_weight_l1[ j ]  = exp_se_golomb(var_bs);
                    chroma_offset_l1[ j ]  = exp_se_golomb(var_bs);
                }
            }
            
        }
    }
    
    return var_ret;
}

int pred_weight_table::put(IBitstream &var_bs, unsigned int num_ref_idx_l0_active_minus1, unsigned int num_ref_idx_l1_active_minus1, unsigned int slice_type) {
    int var_ret = 0;
    luma_log2_weight_denom = 0;
    chroma_log2_weight_denom = 0;
    i = 0;
    j = 0;
    for (i=0; i<=num_ref_idx_l0_active_minus1; i++) {
        var_bs.putbits(luma_weight_l0_flag, 1);
        if (luma_weight_l0_flag)
        {
        }
        
        var_bs.putbits(chroma_weight_l0_flag, 1);
        if (chroma_weight_l0_flag) {
            for (j=0; j<2; j++) {
            }
        }
        
    }
    if (slice_type==1) {
        for (i=0; i<=num_ref_idx_l1_active_minus1; i++) {
            var_bs.putbits(luma_weight_l1_flag, 1);
            if (luma_weight_l1_flag)
            {
            }
            
            var_bs.putbits(chroma_weight_l1_flag, 1);
            if (chroma_weight_l1_flag) {
                for (j=0; j<2; j++) {
                }
            }
            
        }
    }
    
    return var_ret;
}

int dec_ref_pic_marking::get(IBitstream &var_bs, unsigned int nal_unit_type) {
    int var_ret = 0;
    memory_management_control_operation = 0;
    difference_of_pic_nums_minus1 = 0;
    long_term_pic_num = 0;
    long_term_frame_idx = 0;
    max_long_term_frame_idx_plus1 = 0;
    t = 1;
    if (nal_unit_type==5)
    {
        no_output_of_prior_pics_flag = var_bs.getbits(1);
        long_term_reference_flag = var_bs.getbits(1);
    }
    else
    {
        adaptive_ref_pic_marking_mode_flag = var_bs.getbits(1);
        if (adaptive_ref_pic_marking_mode_flag) {
            while (t) {
                memory_management_control_operation  = exp_ue_golomb(var_bs);
                if (memory_management_control_operation==1||memory_management_control_operation==3)
                {
                    difference_of_pic_nums_minus1  = exp_ue_golomb(var_bs);
                }
                
                if (memory_management_control_operation==2)
                {
                    long_term_pic_num  = exp_ue_golomb(var_bs);
                }
                
                if (memory_management_control_operation==3||memory_management_control_operation==6)
                {
                    long_term_frame_idx  = exp_ue_golomb(var_bs);
                }
                
                if (memory_management_control_operation==4)
                {
                    max_long_term_frame_idx_plus1  = exp_ue_golomb(var_bs);
                }
                
                if (memory_management_control_operation==0) {
                    break;
                }
                
            }
        }
        
    }
    
    return var_ret;
}

int dec_ref_pic_marking::put(IBitstream &var_bs, unsigned int nal_unit_type) {
    int var_ret = 0;
    memory_management_control_operation = 0;
    difference_of_pic_nums_minus1 = 0;
    long_term_pic_num = 0;
    long_term_frame_idx = 0;
    max_long_term_frame_idx_plus1 = 0;
    t = 1;
    if (nal_unit_type==5)
    {
        var_bs.putbits(no_output_of_prior_pics_flag, 1);
        var_bs.putbits(long_term_reference_flag, 1);
    }
    else
    {
        var_bs.putbits(adaptive_ref_pic_marking_mode_flag, 1);
        if (adaptive_ref_pic_marking_mode_flag) {
            while (t) {
                if (memory_management_control_operation==1||memory_management_control_operation==3)
                {
                }
                
                if (memory_management_control_operation==2)
                {
                }
                
                if (memory_management_control_operation==3||memory_management_control_operation==6)
                {
                }
                
                if (memory_management_control_operation==4)
                {
                }
                
                if (memory_management_control_operation==0) {
                    break;
                }
                
            }
        }
        
    }
    
    return var_ret;
}

int slice_header::get(IBitstream &var_bs) {
    int var_ret = 0;
    frame_mbs_only_flag = 0;
    nal_unit_type = 0;
    first_mb_in_slice = 0;
    slice_type = 0;
    pic_parameter_set_id = 0;
    frame_num = 0;
    idr_pic_id = 0;
    pic_order_cnt_lsb = 0;
    delta_pic_order_cnt_bottom = 0;
    redundant_pic_cnt = 0;
    num_ref_idx_l0_active_minus1 = 0;
    num_ref_idx_l1_active_minus1 = 0;
    cabac_init_idc = 0;
    slice_qp_delta = 0;
    slice_qs_delta = 0;
    disable_deblocking_filter_idc = 0;
    slice_alpha_c0_offset_div2 = 0;
    slice_beta_offset_div2 = 0;
    slice_group_change_cycle = 0;
    reset();
    frame_mbs_only_flag   = __frame_mbs_only_flag; 
    nal_unit_type         = __nal_unit_type;       
    first_mb_in_slice     = exp_ue_golomb(var_bs);
    slice_type            = exp_ue_golomb(var_bs);
    pic_parameter_set_id  = exp_ue_golomb(var_bs);
    frame_num             = var_bs.getbits(__log2_max_frame_num_minus4 + 4);
    if (!frame_mbs_only_flag)
    {
        field_pic_flag = var_bs.getbits(1);
        if (field_pic_flag) {
            bottom_field_flag = var_bs.getbits(1);
        }
        
    }
    
    if( __nal_unit_type == 5 )
             idr_pic_id  = exp_ue_golomb(var_bs);
    

      if( __pic_order_cnt_type == 0 ) 
      {
             pic_order_cnt_lsb  = var_bs.getbits(__log2_max_pic_order_cnt_lsb_minus4 + 4);

           if( __pic_order_present_flag && !field_pic_flag )
               delta_pic_order_cnt_bottom  = exp_se_golomb(var_bs);
      }

      if( __pic_order_cnt_type == 1 && ! __delta_pic_order_always_zero_flag ) {
          delta_pic_order_cnt[0]  = exp_se_golomb(var_bs);
      	if( __pic_order_present_flag && !field_pic_flag )
         	delta_pic_order_cnt[1]  = exp_se_golomb(var_bs);
      }

      if( __redundant_pic_cnt_present_flag )
          redundant_pic_cnt  = exp_ue_golomb(var_bs);
      
      
    if (slice_type==1) {
        direct_spatial_mv_pred_flag = var_bs.getbits(1);
    }
    
    if (slice_type==0||slice_type==3||slice_type==1)
    {
        num_ref_idx_active_override_flag = var_bs.getbits(1);
        if( num_ref_idx_active_override_flag ) {
			num_ref_idx_l0_active_minus1  = exp_ue_golomb(var_bs);
			if( slice_type == 1 ) /*B*/
				num_ref_idx_l1_active_minus1  = exp_ue_golomb(var_bs);
		
		}
    }
    
    return var_ret;
    _p_rif = new(ref_pic_list_reordering);
    var_ret += _p_rif->get(var_bs, slice_type);
    
      
     

      if((__weighted_pred_flag && ( slice_type == 0 || slice_type == 8 ) ) ||
		( __weighted_bipred_idc == 1 && slice_type == 1 ) )
    {
        _p_pwt = new(pred_weight_table);
        var_ret += _p_pwt->get(var_bs, num_ref_idx_l0_active_minus1, num_ref_idx_l1_active_minus1, slice_type);
    }
    if( __nal_ref_idc != 0 )
    {
        _p_mark = new(dec_ref_pic_marking);
        var_ret += _p_mark->get(var_bs, nal_unit_type);
    }
    

	if( __entropy_coding_mode_flag && slice_type != 0 && slice_type != 3 )
	{cabac_init_idc  = exp_ue_golomb(var_bs);}

	slice_qp_delta  = exp_se_golomb(var_bs)
	;
    if (slice_type==8||slice_type==9)
    {
        if (slice_type==8) {
            sp_for_switch_flag = var_bs.getbits(1);
        }
        
        slice_qs_delta  = exp_se_golomb(var_bs);
    }
    
    
	
	if( __deblocking_filter_control_present_flag ) {
           disable_deblocking_filter_idc  = exp_ue_golomb(var_bs);
           if( disable_deblocking_filter_idc != 1 ) {
             slice_alpha_c0_offset_div2  = exp_se_golomb(var_bs);
           slice_beta_offset_div2  = exp_se_golomb(var_bs);
	   }
	}

	if( __num_slice_groups_minus1	 > 0 &&
            __slice_group_map_type >= 3 && __slice_group_map_type <= 5)
	   slice_group_change_cycle  = var_bs.getbits(
	     static_cast<short>(
			   ceil(log(((double)
				   (
	   			(__pic_size_in_map_units_minus1 + 1) / 
				(__slice_group_change_rate_minus1 + 1)
				+ 1
				   )
				   )))
			)
	       );
	 
	
    return var_ret;
}

int slice_header::put(IBitstream &var_bs) {
    int var_ret = 0;
    frame_mbs_only_flag = 0;
    nal_unit_type = 0;
    first_mb_in_slice = 0;
    slice_type = 0;
    pic_parameter_set_id = 0;
    frame_num = 0;
    idr_pic_id = 0;
    pic_order_cnt_lsb = 0;
    delta_pic_order_cnt_bottom = 0;
    redundant_pic_cnt = 0;
    num_ref_idx_l0_active_minus1 = 0;
    num_ref_idx_l1_active_minus1 = 0;
    cabac_init_idc = 0;
    slice_qp_delta = 0;
    slice_qs_delta = 0;
    disable_deblocking_filter_idc = 0;
    slice_alpha_c0_offset_div2 = 0;
    slice_beta_offset_div2 = 0;
    slice_group_change_cycle = 0;
    if (!frame_mbs_only_flag)
    {
        var_bs.putbits(field_pic_flag, 1);
        if (field_pic_flag) {
            var_bs.putbits(bottom_field_flag, 1);
        }
        
    }
    
    if (slice_type==1) {
        var_bs.putbits(direct_spatial_mv_pred_flag, 1);
    }
    
    if (slice_type==0||slice_type==3||slice_type==1)
    {
        var_bs.putbits(num_ref_idx_active_override_flag, 1);
    }
    
    var_ret += _p_rif->put(var_bs, slice_type);
    {
        var_ret += _p_pwt->put(var_bs, num_ref_idx_l0_active_minus1, num_ref_idx_l1_active_minus1, slice_type);
    }
    {
        var_ret += _p_mark->put(var_bs, nal_unit_type);
    }
    if (slice_type==8||slice_type==9)
    {
        if (slice_type==8) {
            var_bs.putbits(sp_for_switch_flag, 1);
        }
        
    }
    
    return var_ret;
}

int sei_message::get(IBitstream &var_bs) {
    int var_ret = 0;
    payloadType = 0;
    while (var_bs.next(8, 1, 0, 0)==255) {
        ff_byte = var_bs.sgetbits(8);
        payloadType+=255;
    }
    last_payload_type_byte = var_bs.getbits(8);
    payloadType+=last_payload_type_byte;
    payloadSize = 0;
    while (var_bs.next(8, 1, 0, 0)==255) {
        ff_byte = var_bs.sgetbits(8);
        payloadSize+=255;
    }
    last_payload_size_byte = var_bs.getbits(8);
    payloadSize+=last_payload_size_byte;
    return var_ret;
}

int sei_message::put(IBitstream &var_bs) {
    int var_ret = 0;
    payloadType = 0;
    while (var_bs.next(8, 1, 0, 0)==255) {
        var_bs.putbits(ff_byte, 8);
        payloadType+=255;
    }
    var_bs.putbits(last_payload_type_byte, 8);
    payloadType+=last_payload_type_byte;
    payloadSize = 0;
    while (var_bs.next(8, 1, 0, 0)==255) {
        var_bs.putbits(ff_byte, 8);
        payloadSize+=255;
    }
    var_bs.putbits(last_payload_size_byte, 8);
    payloadSize+=last_payload_size_byte;
    return var_ret;
}

int pic_timing::get(IBitstream &var_bs, const H264Sequence *sequence) {
    int var_ret = 0;
    int var_dim0;
    cpb_removal_delay = 0;
    dpb_output_delay = 0;
    time_offset = 0;
    CpbDpbDelaysPresentFlag = 0;
    time_offset_length = 0;
    cpb_removal_delay_length = 0;
    dpb_output_delay_length = 0;
    pic_struct_present_flag = 0;
    NumClockTS = 0;
        
            if(sequence->VUI->nal_hrd_parameters_present_flag)
                  CpbDpbDelaysPresentFlag = 1;
                  
            if(sequence->VUI->vcl_hrd_parameters_present_flag)
                  CpbDpbDelaysPresentFlag = 1;
                  
            if(sequence->VUI->HRD)
            {
                  time_offset_length = sequence->VUI->HRD->time_offset_length;
                  cpb_removal_delay_length  = sequence->VUI->HRD->cpb_removal_delay_length_minus1 + 1;
                  dpb_output_delay_length  = sequence->VUI->HRD->dpb_output_delay_length_minus1 + 1;
            }              
                  
                  
           pic_struct_present_flag = sequence->VUI->pic_struct_present_flag;
           
         
    if (CpbDpbDelaysPresentFlag)
    {
        cpb_removal_delay  = var_bs.getbits(cpb_removal_delay_length);
        dpb_output_delay   = var_bs.getbits(dpb_output_delay_length);
    }
    
    if (pic_struct_present_flag)
    {
        pic_struct = var_bs.getbits(4);
        
			 switch( pic_struct ){
			    case 0:
			    case 1:
			    case 2:
			       NumClockTS = 1;
			       break;
			    
			    case 3:
			    case 4:
			    case 7:
			       NumClockTS = 2;
			       break;
			       
			   case 5:
			   case 6:
			   case 8:
			       NumClockTS = 3;
			       break;
			       
			    
			    
			 }
		
        unsigned int i;
        i = 0;
        for (i=0; i<NumClockTS; i++) {
            var_dim0 = i;
            clock_timestamp_flag[var_dim0] = var_bs.getbits(1);
            if (clock_timestamp_flag[i])
            {
                var_dim0 = i;
                ct_type[var_dim0] = var_bs.getbits(2);
                var_dim0 = i;
                nuit_field_based_flag[var_dim0] = var_bs.getbits(1);
                var_dim0 = i;
                counting_type[var_dim0] = var_bs.getbits(5);
                var_dim0 = i;
                full_timestamp_flag[var_dim0] = var_bs.getbits(1);
                var_dim0 = i;
                discontinuity_flag[var_dim0] = var_bs.getbits(1);
                var_dim0 = i;
                cnt_dropped_flag[var_dim0] = var_bs.getbits(1);
                var_dim0 = i;
                n_frames[var_dim0] = var_bs.getbits(8);
                if (full_timestamp_flag[i])
                {
                    var_dim0 = i;
                    seconds_value[var_dim0] = var_bs.getbits(6);
                    var_dim0 = i;
                    minutes_value[var_dim0] = var_bs.getbits(6);
                    var_dim0 = i;
                    hours_value[var_dim0] = var_bs.getbits(5);
                }
                else
                {
                    var_dim0 = i;
                    seconds_flag[var_dim0] = var_bs.getbits(1);
                    if (seconds_flag)
                    {
                        var_dim0 = i;
                        seconds_value[var_dim0] = var_bs.getbits(6);
                        var_dim0 = i;
                        minutes_flag[var_dim0] = var_bs.getbits(1);
                        if (minutes_flag)
                        {
                            var_dim0 = i;
                            minutes_value[var_dim0] = var_bs.getbits(6);
                            var_dim0 = i;
                            hours_flag[var_dim0] = var_bs.getbits(1);
                            if (hours_flag) {
                                var_dim0 = i;
                                hours_value[var_dim0] = var_bs.getbits(5);
                            }
                            
                        }
                        
                    }
                    
                }
                
                if (time_offset_length>0) {
                    time_offset  = var_bs.getbits(time_offset_length);
                }
                
            }
            
        }
    }
    
    return var_ret;
}

int pic_timing::put(IBitstream &var_bs, const H264Sequence *sequence) {
    int var_ret = 0;
    int var_dim0;
    cpb_removal_delay = 0;
    dpb_output_delay = 0;
    time_offset = 0;
    CpbDpbDelaysPresentFlag = 0;
    time_offset_length = 0;
    cpb_removal_delay_length = 0;
    dpb_output_delay_length = 0;
    pic_struct_present_flag = 0;
    NumClockTS = 0;
    if (CpbDpbDelaysPresentFlag)
    {
    }
    
    if (pic_struct_present_flag)
    {
        var_bs.putbits(pic_struct, 4);
        unsigned int i;
        i = 0;
        for (i=0; i<NumClockTS; i++) {
            var_dim0 = i;
            var_bs.putbits(clock_timestamp_flag[var_dim0], 1);
            if (clock_timestamp_flag[i])
            {
                var_dim0 = i;
                var_bs.putbits(ct_type[var_dim0], 2);
                var_dim0 = i;
                var_bs.putbits(nuit_field_based_flag[var_dim0], 1);
                var_dim0 = i;
                var_bs.putbits(counting_type[var_dim0], 5);
                var_dim0 = i;
                var_bs.putbits(full_timestamp_flag[var_dim0], 1);
                var_dim0 = i;
                var_bs.putbits(discontinuity_flag[var_dim0], 1);
                var_dim0 = i;
                var_bs.putbits(cnt_dropped_flag[var_dim0], 1);
                var_dim0 = i;
                var_bs.putbits(n_frames[var_dim0], 8);
                if (full_timestamp_flag[i])
                {
                    var_dim0 = i;
                    var_bs.putbits(seconds_value[var_dim0], 6);
                    var_dim0 = i;
                    var_bs.putbits(minutes_value[var_dim0], 6);
                    var_dim0 = i;
                    var_bs.putbits(hours_value[var_dim0], 5);
                }
                else
                {
                    var_dim0 = i;
                    var_bs.putbits(seconds_flag[var_dim0], 1);
                    if (seconds_flag)
                    {
                        var_dim0 = i;
                        var_bs.putbits(seconds_value[var_dim0], 6);
                        var_dim0 = i;
                        var_bs.putbits(minutes_flag[var_dim0], 1);
                        if (minutes_flag)
                        {
                            var_dim0 = i;
                            var_bs.putbits(minutes_value[var_dim0], 6);
                            var_dim0 = i;
                            var_bs.putbits(hours_flag[var_dim0], 1);
                            if (hours_flag) {
                                var_dim0 = i;
                                var_bs.putbits(hours_value[var_dim0], 5);
                            }
                            
                        }
                        
                    }
                    
                }
                
                if (time_offset_length>0) {
                }
                
            }
            
        }
    }
    
    return var_ret;
}

__ALX_END_NAMESPACE
