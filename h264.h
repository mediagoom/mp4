/* @mediagen - experiment appveyor linux and win 0.26 -
 *
 * h264.h
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

#ifndef var_h264_h_
#define var_h264_h_

// initial size of parsable arrays: 64

// pragma: array=255

#include "media_parser.h"
#include <math.h>

__ALX_BEGIN_NAMESPACE

/*
Parsing process for Exp-Golomb codes
*/
inline unsigned int exp_ue_golomb(IBitstream &var_bs)
{
   unsigned int b(0);

   int leadingZeroBits = -1;
   for( b = 0; !b; leadingZeroBits++ )
        b = var_bs.getbits( 1 );

   if(!leadingZeroBits)
       return 0;

   unsigned int trailer = var_bs.getbits(leadingZeroBits);
   unsigned int exp     = static_cast<int>(pow(2.0, leadingZeroBits));

   _ASSERTE(exp > 1);

   return exp - 1  + trailer;
}

inline int exp_se_golomb(IBitstream &var_bs)
{
     
    float k = static_cast<float>(exp_ue_golomb(var_bs));
    int   q = (static_cast<int>(k)) + 1;
	  q = static_cast<int>(pow(-1.0, q));
    return static_cast<int>(q*ceil(k/2));
   
    
}



class hrd_parameters {
public:
    unsigned int cpb_cnt_minus1;
    unsigned int bit_rate_value_minus1[255];
    unsigned int cpb_size_value_minus1[255];
    unsigned int bit_rate_scale;
    unsigned int cpb_size_scale;
    unsigned int SchedSelIdx;
    unsigned int cbr_flag;
    unsigned int initial_cpb_removal_delay_length_minus1;
    unsigned int cpb_removal_delay_length_minus1;
    unsigned int dpb_output_delay_length_minus1;
    unsigned int time_offset_length;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class vui_parameters {
public:
    unsigned int chroma_sample_loc_type_top_field;
    unsigned int chroma_sample_loc_type_bottom_field;
    unsigned int max_bytes_per_pic_denom;
    unsigned int max_bits_per_mb_denom;
    unsigned int log2_max_mv_length_horizontal;
    unsigned int log2_max_mv_length_vertical;
    unsigned int num_reorder_frames;
    unsigned int max_dec_frame_buffering;
    unsigned int aspect_ratio_info_present_flag;
    unsigned int aspect_ratio_idc;
    unsigned int sar_width;
    unsigned int sar_height;
    unsigned int overscan_info_present_flag;
    unsigned int overscan_appropriate_flag;
    unsigned int video_signal_type_present_flag;
    unsigned int video_format;
    unsigned int video_full_range_flag;
    unsigned int colour_description_present_flag;
    unsigned int colour_primaries;
    unsigned int transfer_characteristics;
    unsigned int matrix_coefficients;
    unsigned int chroma_loc_info_present_flag;
    unsigned int timing_info_present_flag;
    unsigned int num_units_in_tick;
    unsigned int time_scale;
    unsigned int fixed_frame_rate_flag;
    unsigned int nal_hrd_parameters_present_flag;
    hrd_parameters *HRD;
    unsigned int vcl_hrd_parameters_present_flag;
    hrd_parameters *VLC_HRD;
    unsigned int low_delay_hrd_flag;
    unsigned int pic_struct_present_flag;
    unsigned int bitstream_restriction_flag;
    unsigned int motion_vectors_over_pic_boundaries_flag;
    
public:
       vui_parameters():HRD(NULL),VLC_HRD(NULL){}
      ~vui_parameters()
      {
        //_ASSERTE(!HRD);
		if(HRD)      
          delete HRD;
        if(VLC_HRD)
          delete VLC_HRD;
      }
       

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class H264Sequence {
public:
    unsigned int log2_max_pic_order_cnt_lsb_minus4;
    unsigned int profile_idc;
    unsigned int constraint_set0_flag;
    unsigned int constraint_set1_flag;
    unsigned int constraint_set2_flag;
    unsigned int constraint_set3_flag;
    unsigned int reserved_zero_bits;
    unsigned int level_idc;
    unsigned int seq_parameter_set_id;
    unsigned int chroma_format_idc;
    unsigned int bit_depth_luma;
    unsigned int bit_depth_chroma;
    unsigned int frame_crop_left_offset;
    unsigned int frame_crop_right_offset;
    unsigned int frame_crop_top_offset;
    unsigned int frame_crop_bottom_offset;
    unsigned int offset_for_non_ref_pic;
    unsigned int offset_for_top_to_bottom_field;
    unsigned int num_ref_frames_in_pic_order_cnt_cycle;
    unsigned int residual_color_transform_flag;
    unsigned int transform_bypass;
    unsigned int decode_scaling_matrix;
    unsigned int log2_max_frame_num_minus4;
    unsigned int pic_order_cnt_type;
    unsigned int delta_pic_order_always_zero_flag;
    unsigned int num_ref_frames;
    unsigned int gaps_in_frame_num_value_allowed_flag;
    unsigned int pic_width_in_mbs_minus1;
    unsigned int pic_height_in_map_units_minus1;
    unsigned int frame_mbs_only_flag;
    unsigned int mb_adaptive_frame_field_flag;
    unsigned int direct_8x8_inference_flag;
    unsigned int frame_cropping_flag;
    unsigned int vui_parameters_present_flag;
    vui_parameters *VUI;
    unsigned int rbsp_stop_one_bit;
    unsigned int skip;
    
public:
	 H264Sequence():
		  VUI(NULL)
		, mb_adaptive_frame_field_flag(0)
	 {}
	~H264Sequence(){if(VUI){delete VUI;}}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class pic_parameter_set_rbsp {
public:
    unsigned int pic_parameter_set_id;
    unsigned int seq_parameter_set_id;
    unsigned int num_slice_groups_minus1;
    unsigned int slice_group_map_type;
    unsigned int run_length_minus1[255];
    unsigned int top_left[255];
    unsigned int bottom_right[255];
    unsigned int slice_group_change_rate_minus1;
    unsigned int pic_size_in_map_units_minus1;
    unsigned int slice_group_id[255];
    unsigned int num_ref_idx_l0_active_minus1;
    unsigned int num_ref_idx_l1_active_minus1;
    int pic_init_qp_minus26;
    int pic_init_qs_minus26;
    int chroma_qp_index_offset;
    int second_chroma_qp_index_offset;
    uint64_t start_size;
    unsigned int entropy_coding_mode_flag;
    unsigned int pic_order_present_flag;
    unsigned int slice_group_change_direction_flag;
    unsigned int weighted_pred_flag;
    unsigned int weighted_bipred_idc;
    unsigned int deblocking_filter_control_present_flag;
    unsigned int constrained_intra_pred_flag;
    unsigned int redundant_pic_cnt_present_flag;
    uint64_t end_size;
    unsigned int extended;
    unsigned int transform_8x8_mode_flag;
    unsigned int pic_scaling_matrix_present_flag;
    unsigned int pic_scaling_list_present_flag;
    unsigned int rbsp_stop_one_bit;
    unsigned int skip;
    
	unsigned int _size;
public:
	 pic_parameter_set_rbsp():_size(0){}
	 pic_parameter_set_rbsp(unsigned int size):_size(size){}
	

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ref_pic_list_reordering {
public:
    unsigned int t;
    unsigned int reordering_of_pic_nums_idc;
    unsigned int abs_diff_pic_num_minus1;
    unsigned int long_term_pic_num;
    unsigned int ref_pic_list_reordering_flag_l0;
    unsigned int ref_pic_list_reordering_flag_l1;
    public: virtual int get(IBitstream &var_bs, unsigned int slice_type);
    public: virtual int put(IBitstream &var_bs, unsigned int slice_type);
};

class pred_weight_table {
public:
    unsigned int luma_log2_weight_denom;
    unsigned int chroma_log2_weight_denom;
    int luma_weight_l0[255];
    int luma_offset_l0[255];
    int luma_weight_l1[255];
    int luma_offset_l1[255];
    int chroma_weight_l0[255];
    int chroma_offset_l0[255];
    int chroma_weight_l1[255];
    int chroma_offset_l1[255];
    unsigned int i;
    unsigned int j;
    unsigned int luma_weight_l0_flag;
    unsigned int chroma_weight_l0_flag;
    unsigned int luma_weight_l1_flag;
    unsigned int chroma_weight_l1_flag;
    public: virtual int get(IBitstream &var_bs, unsigned int num_ref_idx_l0_active_minus1, unsigned int num_ref_idx_l1_active_minus1, unsigned int slice_type);
    public: virtual int put(IBitstream &var_bs, unsigned int num_ref_idx_l0_active_minus1, unsigned int num_ref_idx_l1_active_minus1, unsigned int slice_type);
};

class dec_ref_pic_marking {
public:
    unsigned int memory_management_control_operation;
    unsigned int difference_of_pic_nums_minus1;
    unsigned int long_term_pic_num;
    unsigned int long_term_frame_idx;
    unsigned int max_long_term_frame_idx_plus1;
    int t;
    unsigned int no_output_of_prior_pics_flag;
    unsigned int long_term_reference_flag;
    unsigned int adaptive_ref_pic_marking_mode_flag;
    public: virtual int get(IBitstream &var_bs, unsigned int nal_unit_type);
    public: virtual int put(IBitstream &var_bs, unsigned int nal_unit_type);
};

class slice_header {
public:
    
	void reset(){

	if(_p_rif) {delete _p_rif;}_p_rif   = NULL;
	if(_p_pwt) {delete _p_pwt;}_p_pwt   = NULL;
	if(_p_mark){delete _p_mark;}_p_mark = NULL;

	}
	
        //INFORMATION NEEDED FOR PARSING
	//NAL
	unsigned int __nal_unit_type;
	unsigned int __nal_ref_idc;
	//SPS
        unsigned int __log2_max_frame_num_minus4;
	unsigned int __frame_mbs_only_flag;
	unsigned int __pic_order_cnt_type;
	unsigned int __log2_max_pic_order_cnt_lsb_minus4;
	unsigned int __delta_pic_order_always_zero_flag;
	//PPS
	unsigned int __pic_order_present_flag;
	unsigned int __redundant_pic_cnt_present_flag;
	unsigned int __weighted_pred_flag;
        unsigned int __weighted_bipred_idc;
	unsigned int __entropy_coding_mode_flag;
	unsigned int __deblocking_filter_control_present_flag;
	unsigned int __num_slice_groups_minus1;
	unsigned int __slice_group_map_type ;
	unsigned int __slice_group_change_rate_minus1;
	unsigned int __pic_size_in_map_units_minus1;

    unsigned int frame_mbs_only_flag;
    unsigned int nal_unit_type;
    unsigned int first_mb_in_slice;
    unsigned int slice_type;
    unsigned int pic_parameter_set_id;
    unsigned int frame_num;
    unsigned int idr_pic_id;
    unsigned int pic_order_cnt_lsb;
    int delta_pic_order_cnt_bottom;
    int delta_pic_order_cnt[255];
    unsigned int redundant_pic_cnt;
    unsigned int num_ref_idx_l0_active_minus1;
    unsigned int num_ref_idx_l1_active_minus1;
    unsigned int cabac_init_idc;
    int slice_qp_delta;
    int slice_qs_delta;
    unsigned int disable_deblocking_filter_idc;
    int slice_alpha_c0_offset_div2;
    int slice_beta_offset_div2;
    unsigned int slice_group_change_cycle;
    unsigned int field_pic_flag;
    unsigned int bottom_field_flag;
    unsigned int direct_spatial_mv_pred_flag;
    unsigned int num_ref_idx_active_override_flag;
    ref_pic_list_reordering *_p_rif;
    pred_weight_table *_p_pwt;
    dec_ref_pic_marking *_p_mark;
    unsigned int sp_for_switch_flag;
    
    slice_header(unsigned int sps_log2_max_frame_num_minus4
               , unsigned int sps_frame_mbs_only_flag
	       , unsigned int nal_nal_unit_type
	       , unsigned int nal_nal_ref_idc
	       , unsigned int sps_pic_order_cnt_type
	       , unsigned int sps_log2_max_pic_order_cnt_lsb_minus4
	       , unsigned int pps_pic_order_present_flag
	       , unsigned int sps_delta_pic_order_always_zero_flag
	       , unsigned int pps_redundant_pic_cnt_present_flag
	       , unsigned int pps_weighted_pred_flag
               , unsigned int pps_weighted_bipred_idc
	       , unsigned int pps_entropy_coding_mode_flag
	       , unsigned int pps_deblocking_filter_control_present_flag
	       , unsigned int pps_num_slice_groups_minus1
               , unsigned int pps_slice_group_map_type 
	       , unsigned int pps_slice_group_change_rate_minus1
	       , unsigned int pps_pic_size_in_map_units_minus1
	):
          __log2_max_frame_num_minus4(sps_log2_max_frame_num_minus4)
	, __frame_mbs_only_flag(sps_frame_mbs_only_flag)
	, __nal_unit_type(nal_nal_unit_type)
	, __nal_ref_idc(nal_nal_ref_idc)
	, __pic_order_cnt_type(sps_pic_order_cnt_type)
	, __log2_max_pic_order_cnt_lsb_minus4(sps_log2_max_pic_order_cnt_lsb_minus4)
	, __pic_order_present_flag(pps_pic_order_present_flag)
	, __delta_pic_order_always_zero_flag(sps_delta_pic_order_always_zero_flag)
	, __redundant_pic_cnt_present_flag(pps_redundant_pic_cnt_present_flag)
	, __weighted_pred_flag(pps_weighted_pred_flag)
	, __weighted_bipred_idc(pps_weighted_bipred_idc)
	, __entropy_coding_mode_flag(pps_entropy_coding_mode_flag)
	, __deblocking_filter_control_present_flag(pps_deblocking_filter_control_present_flag)
	, __num_slice_groups_minus1(pps_num_slice_groups_minus1)
	, __slice_group_map_type(pps_slice_group_map_type) 
	, __slice_group_change_rate_minus1(pps_slice_group_change_rate_minus1)
	, __pic_size_in_map_units_minus1(pps_pic_size_in_map_units_minus1)
	, _p_rif(NULL)
	, _p_pwt(NULL)
	, _p_mark(NULL)
    {}

    slice_header(const H264Sequence & sps
               , const pic_parameter_set_rbsp & pps
	       , unsigned int nal_nal_unit_type
	       , unsigned int nal_nal_ref_idc
	):
          __log2_max_frame_num_minus4(sps.log2_max_frame_num_minus4)
	, __frame_mbs_only_flag(sps.frame_mbs_only_flag)
	, __nal_unit_type(nal_nal_unit_type)
	, __nal_ref_idc(nal_nal_ref_idc)
	, __pic_order_cnt_type(sps.pic_order_cnt_type)
	, __log2_max_pic_order_cnt_lsb_minus4(sps.log2_max_pic_order_cnt_lsb_minus4)
	, __pic_order_present_flag(pps.pic_order_present_flag)
	, __delta_pic_order_always_zero_flag(sps.delta_pic_order_always_zero_flag)
	, __redundant_pic_cnt_present_flag(pps.redundant_pic_cnt_present_flag)
	, __weighted_pred_flag(pps.weighted_pred_flag)
	, __weighted_bipred_idc(pps.weighted_bipred_idc)
	, __entropy_coding_mode_flag(pps.entropy_coding_mode_flag)
	, __deblocking_filter_control_present_flag(pps.deblocking_filter_control_present_flag)
	, __num_slice_groups_minus1(pps.num_slice_groups_minus1)
	, __slice_group_map_type(pps.slice_group_map_type) 
	, __slice_group_change_rate_minus1(pps.slice_group_change_rate_minus1)
	, __pic_size_in_map_units_minus1(pps.pic_size_in_map_units_minus1)
          
	, _p_rif(NULL)
	, _p_pwt(NULL)
	, _p_mark(NULL)
    {}

    ~slice_header(){reset();}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class sei_message {
public:
    int payloadType;
    char ff_byte;
    unsigned int last_payload_type_byte;
    int payloadSize;
    unsigned int last_payload_size_byte;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class pic_timing {
public:
    unsigned int cpb_removal_delay;
    unsigned int dpb_output_delay;
    unsigned int time_offset;
    unsigned int CpbDpbDelaysPresentFlag;
    unsigned int time_offset_length;
    unsigned int cpb_removal_delay_length;
    unsigned int dpb_output_delay_length;
    unsigned int pic_struct_present_flag;
    unsigned int NumClockTS;
    unsigned int pic_struct;
    unsigned int clock_timestamp_flag[255];
    unsigned int ct_type[255];
    unsigned int nuit_field_based_flag[255];
    unsigned int counting_type[255];
    unsigned int full_timestamp_flag[255];
    unsigned int discontinuity_flag[255];
    unsigned int cnt_dropped_flag[255];
    unsigned int n_frames[255];
    unsigned int seconds_value[255];
    unsigned int minutes_value[255];
    unsigned int hours_value[255];
    unsigned int seconds_flag[255];
    unsigned int minutes_flag[255];
    unsigned int hours_flag[255];
    public: virtual int get(IBitstream &var_bs, const H264Sequence *sequence);
    public: virtual int put(IBitstream &var_bs, const H264Sequence *sequence);
};

__ALX_END_NAMESPACE


#endif /* ! var_h264_h_ */
