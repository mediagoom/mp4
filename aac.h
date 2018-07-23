/* @mediagen - experiment appveyor linux and win 0.26 -
 *
 * aac.h
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

#ifndef var_aac_h_
#define var_aac_h_

// initial size of parsable arrays: 64


__ALX_BEGIN_NAMESPACE


#include "media_parser.h"

enum AudioObjectType {
    AOT_NULL,                  
    AOT_AAC_MAIN,              
    AOT_AAC_LC,                
    AOT_AAC_SSR,               
    AOT_AAC_LTP,               
    AOT_SBR,                   
    AOT_AAC_SCALABLE,          
    AOT_TWINVQ,                
    AOT_CELP,                  
    AOT_HVXC,                  
    AOT_TTSI             = 12, 
    AOT_MAINSYNTH,             
    AOT_WAVESYNTH,             
    AOT_MIDI,                  
    AOT_SAFX,                  
    AOT_ER_AAC_LC,             
    AOT_ER_AAC_LTP       = 19, 
    AOT_ER_AAC_SCALABLE,       
    AOT_ER_TWINVQ,             
    AOT_ER_BSAC,               
    AOT_ER_AAC_LD,             
    AOT_ER_CELP,               
    AOT_ER_HVXC,               
    AOT_ER_HILN,               
    AOT_ER_PARAM,              
    AOT_SSC,                   
    AOT_PS,                    
    AOT_SURROUND,              
    AOT_ESCAPE,                
    AOT_L1,                    
    AOT_L2,                    
    AOT_L3,                    
    AOT_DST,                   
    AOT_ALS,                   
    AOT_SLS,                   
    AOT_SLS_NON_CORE,          
    AOT_ER_AAC_ELD,            
    AOT_SMR_SIMPLE,            
    AOT_SMR_MAIN,              
    AOT_USAC_NOSBR,            
    AOT_SAOC,                  
    AOT_LD_SURROUND,           
    AOT_USAC,                  
};



class mpeg4audio_sample_rates {
    public: static int nextvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse=NULL, int *var_code=NULL);
    public: static int getvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse=NULL, int *var_code=NULL);
    public: static int putvlc(IBitstream &var_bs, unsigned int var_arg, int *var_parse=NULL, int *var_code=NULL);
};

class mpeg4audio_channels {
    public: static int nextvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse=NULL, int *var_code=NULL);
    public: static int getvlc(IBitstream &var_bs, unsigned int *var_arg, int *var_parse=NULL, int *var_code=NULL);
    public: static int putvlc(IBitstream &var_bs, unsigned int var_arg, int *var_parse=NULL, int *var_code=NULL);
};

class aac_info_mp4 {
public:
    unsigned int object_type;
    unsigned int sample_rate;
    unsigned int channels_4_bit;
    unsigned int channels;
    unsigned int frame_length_flag;
    unsigned int depends_core_coder;
    unsigned int core_coder_delay;
    unsigned int extension_flag;
    
    aac_info_mp4()
       : frame_length_flag(0)
       , depends_core_coder(0)
       , core_coder_delay(0)
       , extension_flag(0)
       , channels_4_bit(0)
    {}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ADTS {
public:
    unsigned int syncword;
    unsigned int mpeg_version;
    unsigned int layer;
    unsigned int missing_protection;
    unsigned int mpeg_4_audio_object_minus_1;
    unsigned int mpeg_4_sampling_frequency;
    unsigned int private_bit;
    unsigned int channel_configuration;
    unsigned int private_bit_2;
    unsigned int home;
    unsigned int copyrighted;
    unsigned int copyrighted_start;
    unsigned int frame_length;
    unsigned int buffer_fullnes;
    unsigned int aac_frames_minus_1;
    unsigned int CRC;
    
        ADTS():missing_protection(1)
          , private_bit(0)
          , private_bit_2(0)
          , home(0)
          , copyrighted(0)
          , copyrighted_start(0)
          , aac_frames_minus_1(0)
        {
        }
        
		unsigned int get_body_length()
		{
		   return frame_length - ((missing_protection)?7:9);
		}
		
		void set_body_length(unsigned int length)
		{
		    frame_length = length + ((missing_protection)?7:9);
		}
		
		unsigned int get_mpeg_4_audio_object()
		{
		   return mpeg_4_audio_object_minus_1 + 1;
		}
		
		void set_mpeg_4_audio_object(unsigned int obj)
		{
		    mpeg_4_audio_object_minus_1 = obj - 1;
		}
		
		
    
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_aac_h_ */
