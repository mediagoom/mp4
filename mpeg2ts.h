/* @mediagen - adding stddef.h reference for using size_t -
 *
 * mpeg2ts.h
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

#ifndef var_mpeg2ts_h_
#define var_mpeg2ts_h_

// initial size of parsable arrays: 64

// pragma: array=256
// pragma: get

#include <stdio.h>
#include "media_parser.h"
#include <vector>

const int TRANSPORT_PACKET_SIZE = 188;


__ALX_BEGIN_NAMESPACE

extern const unsigned int private_stream_2;
extern const unsigned int padding_stream;
extern const unsigned int extension_start_code;
extern const unsigned int ST_PSMapTable;
extern const unsigned int ST_Private1;
extern const unsigned int ST_Padding;
extern const unsigned int ST_Private2;
extern const unsigned int ST_Audio1;
extern const unsigned int ST_Audio2;
extern const unsigned int ST_Video1;
extern const unsigned int ST_Video2;
extern const unsigned int ST_ECM;
extern const unsigned int ST_EMM;
extern const unsigned int ST_DSMCC;
extern const unsigned int ST_ISO_13522;
extern const unsigned int ST_ITUT_A;
extern const unsigned int ST_ITUT_B;
extern const unsigned int ST_ITUT_C;
extern const unsigned int ST_ITUT_D;
extern const unsigned int ST_ITUT_E;
extern const unsigned int ST_PSDirectory;
extern const unsigned int fast_forward;
extern const unsigned int slow_motion;
extern const unsigned int freeze_frame;
extern const unsigned int fast_reverse;
extern const unsigned int slow_reverse;

class MpegTime {
public:
    
		static uint64_t Time(unsigned int t32_30, unsigned int t29_15, unsigned int t14_0, unsigned int ext)
		{
			uint64_t SCR;
			double scr_val(0);
	
			SCR = t32_30; //SCR 32..30
			//scr_val= (SCR>3)?4294967296.0:0.0;	// caz pt. SCR[32]=1 -> overflow
			SCR = SCR << 30;
			SCR |= t29_15 << 15;           //SCR 29..15
			SCR |= t14_0;

			scr_val += static_cast<double>(SCR);
    
			scr_val *= 300.0;
	
			SCR  = ext;		// SCR_ext
	
			scr_val += static_cast<double>(SCR);
			scr_val = scr_val/27000.0;	

			return static_cast<uint64_t>(scr_val * 10000);

		}

        static uint64_t Time(unsigned int t32_30, unsigned int t29_15, unsigned int t14_0)
		{
			return Time(t32_30, t29_15, t14_0, 0);
		}

        static void ToMpegTime(uint64_t time, unsigned int &t32_30, unsigned int &t29_15, unsigned int &t14_0, unsigned int &ext)
		{
			uint64_t system_clock_frequency = 27000;

			time = time / 10000;

	

			uint64_t pcr_base =  (time * system_clock_frequency)/300;//((system_clock_frequency * time)/300)%(2^33);
			uint64_t pcr_ext  =  (time * system_clock_frequency)%300;//((system_clock_frequency * time)%(300*2^33)) - (pcr_base*300);
    
			t32_30 = static_cast<uint32_t>( pcr_base >> 30 );
			t29_15 = (pcr_base & 0x2FFFFFFF) >> 15;
			t14_0  = (pcr_base & 0x00007FFF);
			ext    =  static_cast<uint32_t>(pcr_ext);

    
		}


        static void ToMpegTime(uint64_t time, unsigned int &t32_30, unsigned int &t29_15, unsigned int &t14_0)
		{
			unsigned int ext(0);

			ToMpegTime(time, t32_30, t29_15, t14_0, ext);
		}



	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SystemHeaderStream {
public:
    unsigned int stream_id;
    unsigned int bit_pattern;
    unsigned int P_STD_buffer_bound_scale;
    unsigned int P_STD_buffer_size_bound;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SystemHeader {
public:
    unsigned int packet_start_code_prefix;
    unsigned int id;
    unsigned int header_length;
    unsigned int marker;
    unsigned int rate_bound;
    unsigned int audio_bound;
    unsigned int fixed_flag;
    unsigned int CSPS_flag;
    unsigned int system_audio_lock_flag;
    unsigned int system_video_lock_flag;
    unsigned int video_bound;
    unsigned int packet_rate_restriction_flag;
    unsigned int reserved;
    int i;
    unsigned int stream_id[256];
    unsigned int bit_pattern;
    unsigned int P_STD_buffer_bound_scale[256];
    unsigned int P_STD_buffer_size_bound[256];
    
    void print_error() { printf("Error in SystemHeader! Wrong stream_id!"); } 
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PackHeader {
public:
    unsigned int packet_start_code_prefix;
    unsigned int id;
    unsigned int bit_pattern;
    unsigned int system_clock_ref_1;
    unsigned int marker;
    unsigned int system_clock_ref_2;
    unsigned int system_clock_ref_3;
    unsigned int system_clock_ref_extension;
    unsigned int program_mux_rate;
    unsigned int reserved;
    unsigned int stuffing_len;
    unsigned int i;
    unsigned int stuffing_byte;
     uint64_t GetTime() const {return MpegTime::Time(system_clock_ref_1, system_clock_ref_2, system_clock_ref_3, system_clock_ref_extension);}
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class base_program_descriptor {
public:
    unsigned int tag;
    unsigned int length;
    unsigned int des_byte_count;
    unsigned char descriptor_data_byte[256];
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class BaseProgramDescriptor {
public:
    unsigned int tag;
    uint64_t var_lengthof;
    unsigned int length;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class VideoDescriptor : public BaseProgramDescriptor {
public:
    unsigned int multiple_frame_rate_flag;
    unsigned int frame_rate_code;
    unsigned int MPEG1_only_flag;
    unsigned int constrained_parameter_flag;
    unsigned int still_picture_flag;
    unsigned int profile_and_level_indication;
    unsigned int chroma_format;
    unsigned int frame_rate_extension_flag;
    unsigned int reserved;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class AudioDescriptor : public BaseProgramDescriptor {
public:
    unsigned int free_format_flag;
    unsigned int ID;
    unsigned int layer;
    unsigned int variable_rate_audio_indicator;
    unsigned int reserved;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class HierarchyDescriptor : public BaseProgramDescriptor {
public:
    unsigned int reserved;
    unsigned int hierarchy_type;
    unsigned int hierarchy_layer_index;
    unsigned int hierarchy_embedded_layer_index;
    unsigned int hierarchy_channel;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class RegistrationDescriptor : public BaseProgramDescriptor {
public:
    unsigned int format_identifier;
    unsigned int bytes_read;
    unsigned int additional_identification_info;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class DataAlignmentDescriptor : public BaseProgramDescriptor {
public:
    unsigned int alignment_type;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class TargetBackgroundGridDescriptor : public BaseProgramDescriptor {
public:
    unsigned int horizontal_size;
    unsigned int vertical_size;
    unsigned int aspect_ratio_information;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class VideoWindowDescriptor : public BaseProgramDescriptor {
public:
    unsigned int horizontal_offset;
    unsigned int vertical_offset;
    unsigned int window_priority;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class ConditionalAccessDescriptor : public BaseProgramDescriptor {
public:
    unsigned int CA_system_ID;
    unsigned int reserved;
    unsigned int CA_PID;
    unsigned int bytes_read;
    unsigned int private_data_byte;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class LanguageDescriptor : public BaseProgramDescriptor {
public:
    unsigned int bytes_read;
    unsigned int ISO_639_language_code;
    unsigned int audio_type;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class SystemClockDescriptor : public BaseProgramDescriptor {
public:
    unsigned int external_clock_reference_indicator;
    unsigned int reserved;
    unsigned int clock_accuracy_indicator;
    unsigned int clock_accuracy_exponent;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MultiplexBufferUtilizationDescriptor : public BaseProgramDescriptor {
public:
    unsigned int bound_valid_flag;
    unsigned int LTW_offset_lower_bound;
    unsigned int reserved;
    unsigned int LTW_offset_upper_bound;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class CopyrightDescriptor : public BaseProgramDescriptor {
public:
    unsigned int copyright_identifier;
    unsigned int bytes_read;
    unsigned int additional_copyright_info;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MaximumBitrateDescriptor : public BaseProgramDescriptor {
public:
    unsigned int reserved;
    unsigned int maximum_bitrate;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class PrivateDataIndicatorDescriptor : public BaseProgramDescriptor {
public:
    unsigned int private_data_indicator;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class SmoothingBufferDescriptor : public BaseProgramDescriptor {
public:
    unsigned int reserved;
    unsigned int sb_leak_rate;
    unsigned int sb_size;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class STDDescriptor : public BaseProgramDescriptor {
public:
    unsigned int reserved;
    unsigned int leak_valid_flag;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class IBPDescriptor : public BaseProgramDescriptor {
public:
    unsigned int closed_gop_flag;
    unsigned int identical_gop_flag;
    unsigned int max_gop_length;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class base_stream_descriptor {
public:
    
private:
      
      std::vector<base_program_descriptor*> _program_descriptor;
      void cleanup()
      {
          for(unsigned int i = 0; i <  _program_descriptor.size(); i++)
				delete  _program_descriptor[i];
	 
		  _program_descriptor.clear();
      }
public:
      virtual ~base_stream_descriptor()
      {
        cleanup();
      }
      
      int parsed_size()
      {
         return 3 + elementary_stream_info_length;
      }

    unsigned int elementary_stream_id;
    unsigned int elementary_stream_info_length;
    uint64_t parsedBytes;
    base_program_descriptor *descriptor;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class BaseStreamDescriptor {
public:
    unsigned int type;
    uint64_t var_lengthof;
    unsigned int elementary_stream_id;
    unsigned int elementary_stream_info_length;
    uint64_t parsedBytes;
    BaseProgramDescriptor *descriptor;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MPEG1VideoStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MPEG2VideoStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MPEG1AudioStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MPEG2AudioStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class PrivateStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class PrivatePESDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class MHEGStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class DSMCCStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class H222_1StreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class ATypeStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class BTypeStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class CTypeStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class DTypeStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class AuxiliaryStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class ReservedStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class UserPrivateStreamDescriptor : public BaseStreamDescriptor {
public:
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class TrickModeControl {
public:
    unsigned int trick_mode_control;
    unsigned int field_id;
    unsigned int intra_slice_refresh;
    unsigned int frequency_truncation;
    unsigned int rep_ctrl;
    unsigned int reserved;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PesBase {
public:
    unsigned int packet_start_code_prefix;
    unsigned int stream_id;
    unsigned int PES_packet_length;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PSMapTable : public PesBase {
public:
    unsigned int current_next_indicator;
    unsigned int reserved;
    unsigned int program_stream_map_version;
    unsigned int marker;
    unsigned int program_stream_info_length;
    uint64_t parsed;
    BaseProgramDescriptor *program_descriptor;
    unsigned int elementary_stream_map_length;
    uint64_t stream_map_ct;
    BaseStreamDescriptor *stream_descriptor;
    unsigned int CRC_32;
    
    void print_error() { printf("Error in PSMapTable! The PES_packet_length is too high!"); } 
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PSDirectory : public PesBase {
public:
    unsigned int number_of_access_units;
    unsigned int marker;
    unsigned int previous_directory_offset_1;
    unsigned int previous_directory_offset_2;
    unsigned int previous_directory_offset_3;
    unsigned int previous_directory_offset_4;
    unsigned int previous_directory_offset_5;
    unsigned int previous_directory_offset_6;
    unsigned int i;
    unsigned int packet_stream_id;
    int PES_header_position_offset_sign;
    unsigned int PES_header_position_offset_1;
    unsigned int PES_header_position_offset_2;
    unsigned int PES_header_position_offset_3;
    unsigned int reference_offset;
    unsigned int reserved;
    unsigned int PTS_1;
    unsigned int PTS_2;
    unsigned int PTS_3;
    unsigned int bytes_to_read;
    unsigned int intra_coded_indicator;
    unsigned int coding_parameters_indicator;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PesData : public PesBase {
public:
    unsigned int check;
    unsigned int PES_scrambling_control;
    unsigned int PES_priority;
    unsigned int data_alignment_indicator;
    unsigned int copyright;
    unsigned int original_or_copy;
    unsigned int PTS_flags;
    unsigned int DTS_flags;
    unsigned int ESCR_flag;
    unsigned int ES_rate_flag;
    unsigned int DSM_trick_mode_flag;
    unsigned int additional_copy_info_flag;
    unsigned int PES_CRC_flag;
    unsigned int PES_extension_flag;
    unsigned int PES_header_data_length;
    unsigned int check2;
    unsigned int PTS_32_30;
    unsigned int marker_bit;
    unsigned int PTS_29_15;
    unsigned int PTS_14_0;
    unsigned int DTS_32_30;
    unsigned int DTS_29_15;
    unsigned int DTS_14_0;
    unsigned int reserved;
    unsigned int ESCR_base_32_30;
    unsigned int ESCR_base_29_15;
    unsigned int ESCR_base_14_0;
    unsigned int ESCR_extension;
    unsigned int ES_rate;
    unsigned int trick_mode_control;
    unsigned int field_id;
    unsigned int intra_slice_refresh;
    unsigned int frequency_truncation;
    unsigned int field_rep_cntrl;
    unsigned int additional_copy_info;
    unsigned int previous_PES_packet_CRC;
    unsigned int PES_private_data_flag;
    unsigned int pack_header_field_flag;
    unsigned int program_packet_sequence_counter_flag;
    unsigned int P_STD_buffer_flag;
    unsigned int reserved_Pes;
    unsigned int PES_extension_field_flag;
    unsigned int PES_private_data_1;
    unsigned int PES_private_data_2;
    unsigned int PES_private_data_3;
    unsigned int PES_private_data_4;
    unsigned int pack_field_length;
    unsigned int program_packet_sequence_counter;
    unsigned int original_stuff_length;
    unsigned int P_STD_Reserved;
    unsigned int P_STD_buffer_scale;
    unsigned int P_STD_buffer_size;
    unsigned int PES_extension_field_length;
    unsigned int stuffing_byte;
     
		unsigned int getHeaderSize() const
		{
			if (stream_id == private_stream_2 || stream_id == padding_stream) 
			{return 6;}

			return 9 + PES_header_data_length;
		}
        //<summary>Return the compleate size of the pes PayLoad</summary>
		unsigned int getBodySize() const
		{			
			unsigned int len   = getHeaderSize();
			unsigned int bytes = 6 + PES_packet_length - len;
			return bytes;
		}

		uint64_t GetTime() const {return MpegTime::Time(PTS_32_30, PTS_29_15, PTS_14_0);}
		uint64_t GetDTSTime() const {return MpegTime::Time(DTS_32_30, DTS_29_15, DTS_14_0);}
		bool IsVideo() const {return (stream_id >= 0xE0 && stream_id <= 0xEF);}
		bool IsAudio() const {return (stream_id >= 0xC0 && stream_id <= 0xDF);}
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PesPadding : public PesBase {
public:
    unsigned int st_id;
    unsigned int i;
    unsigned int padding_byte;
    public: virtual int get(IBitstream &var_bs, int var_id_parsed = 0);
    public: virtual int put(IBitstream &var_bs, int var_id_parsed = 0);
};

class Adaptation_Field {
public:
    unsigned int adaptation_field_length;
    unsigned int discontinuity_indicator;
    unsigned int random_access_indicator;
    unsigned int elementary_stream_priority_indicator;
    unsigned int PCR_flag;
    unsigned int OPCR_flag;
    unsigned int splicing_point_flag;
    unsigned int transport_private_data_flag;
    unsigned int adaptation_field_extension_flag;
    unsigned int program_clock_ref_1;
    unsigned int program_clock_ref_2;
    unsigned int program_clock_ref_3;
    unsigned int reserved;
    unsigned int program_clock_reference_extension;
    unsigned int original_program_clock_ref_1;
    unsigned int original_program_clock_ref_2;
    unsigned int original_program_clock_ref_3;
    unsigned int original_reserved;
    unsigned int original_program_clock_reference_extension;
    unsigned int splice_countdown;
    unsigned int transport_private_data_length;
    unsigned char private_data_byte[256];
    unsigned int adaptation_field_extension_length;
    
	Adaptation_Field():
		  PCR_flag(0)
		, discontinuity_indicator(0)
		, random_access_indicator(0)
	{}
	Adaptation_Field& operator&(Adaptation_Field& rhs)
	{
	    adaptation_field_length = rhs.adaptation_field_length;
		if(adaptation_field_length > 0 && adaptation_field_length <= 183) 
		{
			discontinuity_indicator = rhs.discontinuity_indicator;
			random_access_indicator = rhs.random_access_indicator;
			elementary_stream_priority_indicator = rhs.elementary_stream_priority_indicator;
			PCR_flag = rhs.PCR_flag;
			OPCR_flag = rhs.OPCR_flag;
			splicing_point_flag = rhs.splicing_point_flag;
			transport_private_data_flag = rhs.transport_private_data_flag;
			adaptation_field_extension_flag = rhs.adaptation_field_extension_flag;

			if(PCR_flag == 0x1) 
			{
				program_clock_ref_1 = rhs.program_clock_ref_1;
				program_clock_ref_2 = rhs.program_clock_ref_2;
				program_clock_ref_3 = rhs.program_clock_ref_3;
				reserved = rhs.reserved;
				program_clock_reference_extension = rhs.program_clock_reference_extension;

			}

			if(OPCR_flag == 0x1) 
			{
				original_program_clock_ref_1 = rhs.original_program_clock_ref_1;
				original_program_clock_ref_2 = rhs.original_program_clock_ref_2;
				original_program_clock_ref_3 = rhs.original_program_clock_ref_3;
				original_reserved = rhs.original_reserved;
				original_program_clock_reference_extension = rhs.original_program_clock_reference_extension;

			}

			if (splicing_point_flag == 0x1) 
			{
				splice_countdown = rhs.splice_countdown;
			}
			
			if(transport_private_data_flag == 1) 
			{
				transport_private_data_length = rhs.transport_private_data_length;
				for (unsigned int i=0; i < transport_private_data_length; i++)
				{
					private_data_byte[i] = rhs.private_data_byte[i];
				}
			}
			
			adaptation_field_extension_length = rhs.adaptation_field_extension_length;
			
		}
	}
	
	Adaptation_Field(Adaptation_Field &rhs)
	{
		operator=(rhs);
	}
	
	uint64_t get_pcr()
	{
	   return 
	   MpegTime::Time
	   (  program_clock_ref_1
		, program_clock_ref_2
		, program_clock_ref_3
		, program_clock_reference_extension);
	}
	
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class Pointer_Field {
public:
    unsigned int pointer_field;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class BaseSection {
public:
    unsigned int table_id;
    unsigned int section_syntax_indicator;
    unsigned int marker;
    unsigned int reserved;
    unsigned int section_length;
    unsigned int id;
    unsigned int reserved2;
    unsigned int version_number;
    unsigned int current_next_indicator;
    unsigned int section_number;
    unsigned int last_section_number;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class Program_Association_Section : public BaseSection {
public:
    unsigned int i;
    unsigned int program_number[256];
    unsigned int reserved3;
    unsigned int network_PID;
    unsigned int program_map_PID[256];
    unsigned int CRC_32;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class Program_Map_Section : public BaseSection {
public:
    
private:
      
      std::vector<base_program_descriptor*> _program_descriptor;
      std::vector<std::vector<base_program_descriptor*>* > _stream_descriptors;
      
      void cleanup()
      {
          for(unsigned int i = 0; i <  _program_descriptor.size(); i++)
				delete  _program_descriptor[i];
	 
		  _program_descriptor.clear();
		  
		  for(unsigned int i = 0; i < _stream_descriptors.size(); i++)
		  {
			    for(unsigned int k = 0; k < _stream_descriptors[i]->size(); k++)
			    {
					delete (*_stream_descriptors[i])[k];
			    }
		  
				_stream_descriptors[i]->clear();
				
				delete _stream_descriptors[i];
		  }
		  
		  _stream_descriptors.clear();
      }
public:
      virtual ~Program_Map_Section()
      {
        cleanup();
      }

    unsigned int reserved3;
    unsigned int PCR_PID;
    unsigned int reserved4;
    unsigned int program_info_length;
    unsigned int des_byte_count;
    base_program_descriptor *descriptor;
    unsigned int program_byte_count;
    unsigned int stream_count;
    unsigned int stream_type[256];
    unsigned int reserved5;
    unsigned int elementary_PID[256];
    unsigned int reserved6;
    unsigned int ES_info_length;
    unsigned int CRC_32;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class Transport_Packet {
public:
    unsigned int transport_error_indicator;
    unsigned int payload_unit_start_indicator;
    unsigned int transport_priority;
    unsigned int PID;
    unsigned int transport_scrambling_control;
    unsigned int adaptation_flag;
    unsigned int payload_field;
    unsigned int continuity_counter;
    Adaptation_Field *adaptation_field;
    unsigned char payload_after_adaptation_byte[256];
    unsigned char payload_byte[256];
    
	  
	  uint64_t _packet_count;
	
     Transport_Packet():
	                      adaptation_field(0)
	                    , _packet_count(0)
	                    {}

		virtual void CleanUp()
		{
			if(adaptation_field)
			{
				delete adaptation_field;
				adaptation_field = 0;
			}
		}
		virtual ~Transport_Packet()
		{
			//if(adaptation_flag == 1)
			//{
				CleanUp();
			//}
		}
		
		Transport_Packet& operator=(Transport_Packet &rhs)
		{
			transport_error_indicator = rhs.transport_error_indicator;
            payload_unit_start_indicator = rhs.payload_unit_start_indicator;
			transport_priority = rhs.transport_priority;
			PID = rhs.PID;
			transport_scrambling_control = rhs.transport_scrambling_control;
			adaptation_flag = rhs.adaptation_flag;
			payload_field = rhs.payload_field;
			continuity_counter = rhs.continuity_counter;
            
            if(adaptation_flag == 1)
			{
				*adaptation_field = *rhs.adaptation_field;

				if(payload_field == 1 && adaptation_field->adaptation_field_length <= 183)
				{
					unsigned int i = 0;
					for (i=0; i < (183 - adaptation_field->adaptation_field_length); i++)
					{
						payload_after_adaptation_byte[i] = rhs.payload_after_adaptation_byte[i];
					}
				}
			}
			else
			{
				if(payload_field == 1)
				{
					int i = 0;
					for (i=0; i < 184; i++)
					{
						payload_byte[i] = rhs.payload_byte[i];
					}
				}
			}
			
			return *this;
		}
		
		//copy constructor
		Transport_Packet(Transport_Packet &rhs)
		{
		    operator=(rhs);
		}
		
		
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SequenceExtension {
public:
    unsigned int extension_start_code;
    unsigned int extension_start_code_identifier;
    unsigned int profile_and_level_indication;
    unsigned int progressive_sequence;
    unsigned int chroma_format;
    unsigned int horizontal_size_extension;
    unsigned int vertical_size_extension;
    unsigned int bit_rate_extension;
    unsigned int marker_bit;
    unsigned int vbv_buffer_size_extension;
    unsigned int low_delay;
    unsigned int frame_rate_extension_n;
    unsigned int frame_rate_extension_d;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SequenceHeader {
public:
    unsigned int packet_start_code_prefix;
    unsigned int stream_id;
    unsigned int horizontal_size_value;
    unsigned int vertical_size_value;
    unsigned int aspect_ratio_information;
    unsigned int frame_rate_code;
    unsigned int bit_rate_value;
    unsigned int marker_bit;
    unsigned int vbv_buffer_size_value;
    unsigned int constrained_parameters_flag;
    unsigned int load_intra_quantiser_matrix;
    char intra_quantiser_matrix[256];
    unsigned int load_non_intra_quantiser_matrix;
    char non_intra_quantiser_matrix[256];
    SequenceExtension *sequenceextension;
    
		SequenceHeader():sequenceextension(0){}

		SequenceHeader(SequenceHeader &rhs)
		{
			operator=(rhs);
		}

	    SequenceHeader& operator=(SequenceHeader &rhs)
		{
			packet_start_code_prefix = rhs.packet_start_code_prefix;
            stream_id = rhs.stream_id;
            horizontal_size_value = rhs.horizontal_size_value;
            vertical_size_value = rhs.vertical_size_value;
            aspect_ratio_information = rhs.aspect_ratio_information;
            frame_rate_code = rhs.frame_rate_code;
            bit_rate_value = rhs.bit_rate_value;
            marker_bit  = rhs.marker_bit;
            vbv_buffer_size_value = rhs.vbv_buffer_size_value;
            constrained_parameters_flag = rhs.constrained_parameters_flag;
             load_intra_quantiser_matrix = 0;//rhs.load_intra_quantiser_matrix;
			//if(1 == load_intra_quantiser_matrix)
			//{
			//	intra_quantiser_matrix = rhs.intra_quantiser_matrix;
			//}
			load_non_intra_quantiser_matrix = 0;//rhs.load_non_intra_quantiser_matrix;
			//if(1 ==load_non_intra_quantiser_matrix)
			//{
			//	non_intra_quantiser_matrix = rhs.non_intra_quantiser_matrix;
			//}

			if(rhs.sequenceextension)
			{
				sequenceextension = new SequenceExtension(*rhs.sequenceextension);
			}
			else
			{
				if(sequenceextension)
				{
					delete sequenceextension;
				}
				sequenceextension = 0;
			}

			return *this;
		}


		virtual ~SequenceHeader()
		{
			if(sequenceextension)
			{
				delete sequenceextension;
			}
		}
		unsigned int getBitRate() const
		{
			unsigned int bit_rate = bit_rate_value;

			if(sequenceextension)
			{
				bit_rate += (sequenceextension->bit_rate_extension << 18);
			}

			return bit_rate*400;
		}
        unsigned int getByteRate() const 
		{
			return getBitRate()/8;
		}

		unsigned int getHorizontal_size() const 
		{
			unsigned int h = horizontal_size_value;
			if(sequenceextension)
			{
				h += (sequenceextension->horizontal_size_extension << 12);
			}

			return h;
		}
		unsigned int getVertical_size() const 
		{
			unsigned int v = vertical_size_value;
			if(sequenceextension)
			{
				v += (sequenceextension->vertical_size_extension << 12);
			}

			return v;
		}
		double getFrame_rate() const 
		{
			double f = 0;

			switch(frame_rate_code)
			{
			case 1:
					 f = 23.976;
				break;
			case 2:
				     f = 24;
				 break;
			case 3: 
				f = 25;
				break;
			case 4:
				f = 29.97;
				break;
			case 5:
				f = 30;
				break;
			case 6:
				f = 50;
				break;
			case 7:
				f = 59.94;
			   break;
			case 8:
				f = 60;
				break;
			}

			if(sequenceextension)
			{
				if(0 != sequenceextension->frame_rate_extension_n ||
					0 != sequenceextension->frame_rate_extension_d )
				{
					return frame_rate_code * 
					(sequenceextension->frame_rate_extension_n + 1) / 
					(sequenceextension->frame_rate_extension_d + 1);
				}
			}

			return f;

		}
		
		const uint64_t get_frame_duration() const {return static_cast<uint64_t>((1000ULL * 10000ULL) / getFrame_rate());}
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class MpegHeaderInfo {
public:
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PitcureBase {
public:
    unsigned int picture_start_code;
    unsigned int temporal_reference;
    unsigned int picture_coding_type;
    unsigned int vbv_delay;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PitcureInfo : public PitcureBase {
public:
    unsigned int garbage;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class Picture_Coding_Extension {
public:
    unsigned int extension_start_code;
    unsigned int extension_start_code_identifier;
    unsigned int f_code1;
    unsigned int f_code2;
    unsigned int f_code3;
    unsigned int f_code4;
    unsigned int intra_dc_precision;
    unsigned int picture_structure;
    unsigned int top_field_first;
    unsigned int frame_pred_frame_dct;
    unsigned int concealment_motion_vectors;
    unsigned int q_scale_type;
    unsigned int intra_vlc_format;
    unsigned int alternate_scan;
    unsigned int repeat_first_field;
    unsigned int chroma_420_type;
    unsigned int progressive_frame;
    unsigned int composite_display_flag;
    unsigned int v_axis;
    unsigned int field_sequence;
    unsigned int sub_carrier;
    unsigned int burst_amplitude;
    unsigned int sub_carrier_phase;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PitcureHeader : public PitcureBase {
public:
    int x;
    unsigned int full_pel_forward_vector;
    unsigned int forward_f_code;
    unsigned int full_pel_backward_vector;
    unsigned int backward_f_code;
    unsigned int extra_bit_picture;
    unsigned int extra_information_picture;
    Picture_Coding_Extension *pictureextension;
    
		PitcureHeader():pictureextension(0){}

		virtual void CleanUp()
		{
			if(pictureextension)
			{
				delete pictureextension;
				pictureextension = 0;
			}
		}
		virtual ~PitcureHeader()
		{
			CleanUp();
		}
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class GroupOfPictureHeader {
public:
    unsigned int gop_start_code;
    unsigned int drop_frame_flag;
    unsigned int time_code_hours;
    unsigned int time_code_minutes;
    unsigned int marker_bit;
    unsigned int time_code_seconds;
    unsigned int time_code_pictures;
    unsigned int closed_gop;
    unsigned int broken_link;
    unsigned int filler;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_mpeg2ts_h_ */
