/* @mediagen - update readme -
 *
 * mpeg2au.h
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

#ifndef var_mpeg2au_h_
#define var_mpeg2au_h_

// initial size of parsable arrays: 64


#include "media_parser.h"


__ALX_BEGIN_NAMESPACE

extern const unsigned int LAYER1;
extern const unsigned int LAYER2;
extern const unsigned int LAYER3;
extern const int SINGLE_CHANNEL;
extern const int DUAL_CHANNEL;
extern const int JOINT_STEREO;
extern const int STEREO;
extern const int BITRATE[4][4][16];
extern const int SAMPLING_FREQ[4][4];
extern const int COEFFICIENTS[2][3];

class AudioHeader {
public:
    unsigned int syncword;
    unsigned int id;
    unsigned int layer;
    unsigned int protection_bit;
    unsigned int bitrate_index;
    unsigned int sampling_frequency;
    unsigned int padding_bit;
    unsigned int private_bit;
    unsigned int mode;
    unsigned int mode_extension;
    unsigned int copyright;
    unsigned int original_copy;
    unsigned int emphasis;
    
		
		AudioHeader():layer(0){}
		
				unsigned int getBitRate() const{return BITRATE[id][layer][bitrate_index] * 1000;}
        unsigned int getByteRate()   const {return getBitRate()/8;}
		unsigned int getChannels()   const {return (mode == SINGLE_CHANNEL) ? 1 : 2; }
		         int getFrequency()  const {return SAMPLING_FREQ[id][sampling_frequency];}
		unsigned int getFrameLength()const {
										
										unsigned int ll = getLayer();
										if(1 > ll)
											return 0;
										
										int lf = (0x3 == id)?0:1;
										int c  = COEFFICIENTS[lf][(getLayer()-1)];
										unsigned int l = (0x3 == layer)? 
									(c * (getBitRate()) / getFrequency() + padding_bit) * 4:
									 c * (getBitRate()) / getFrequency() + padding_bit;

						return l;
		}
		uint64_t getFrameTime() const{return static_cast<uint64_t>(((double)getFrameLength()/(double)getByteRate())*10000000);}
		unsigned int getLayer() const
		{
			if(LAYER1==layer)
				return 1;
			if(LAYER2==layer)
				return 2;
			if(LAYER3==layer)
				return 3;

			return 0;
		}
		float getFrame_rate() const
		{
			return ((float)10000000)/((float)getFrameTime());
		}
		
		bool operator==(AudioHeader rhs) const
		{
		    return syncword == rhs.syncword 
				&& id == rhs.id 
				&& layer == rhs.layer 
				&& protection_bit == rhs.protection_bit 
				&& bitrate_index == rhs.bitrate_index 
				&& sampling_frequency == rhs.sampling_frequency 
				&& padding_bit == rhs.padding_bit 
				&& private_bit == rhs.private_bit 
				&& mode == rhs.mode 
				&& mode_extension == rhs.mode_extension 
				&& copyright == rhs.copyright 
				&& original_copy == rhs.original_copy 
				&& emphasis == rhs.emphasis ;

		}
		
		bool IsValid()
		{
		  return       0 < layer && 4 > layer 
					&& getFrameLength() > 0
					&& getBitRate() > 0
					&& getFrequency() > 0
					;
		}
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ID3 {
public:
    unsigned int ID_1;
    unsigned int ID_2;
    unsigned int ID_3;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ID2V2_3 : public ID3 {
public:
    unsigned int Version;
    unsigned int Revision;
    unsigned int Flags;
    unsigned int ExperimentalIndicator;
    unsigned int Extendedheader;
    unsigned int Unsynchronisation;
    unsigned int check;
    unsigned int size1;
    unsigned int size2;
    unsigned int size3;
    unsigned int size4;
    unsigned int Size;
    
		
	
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_mpeg2au_h_ */
