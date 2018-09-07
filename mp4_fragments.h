/* @mediagen - remove  test_multiple_bitrate.py from make test -
 *
 * mp4_fragments.h
 * 
 * This file was automatically generated
 * from the source file:
 *     'mp4_fragments.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#ifndef var_mp4_fragments_h_
#define var_mp4_fragments_h_

// initial size of parsable arrays: 64

// pragma: array=256
// pragma: get
#include "mp4.h"


const unsigned int box_MVEX = BOX( 'm', 'v', 'e', 'x' );
const unsigned int box_MEHD = BOX( 'm', 'e', 'h', 'd' );
const unsigned int box_TREX = BOX( 't', 'r', 'e', 'x' );
const unsigned int box_MFHD = BOX( 'm', 'f', 'h', 'd' );
const unsigned int box_TFHD = BOX( 't', 'f', 'h', 'd' );
const unsigned int box_TRUN = BOX( 't', 'r', 'u', 'n' );
const unsigned int box_TFRA = BOX( 't', 'f', 'r', 'a' );
const unsigned int box_MOOF = BOX( 'm', 'o', 'o', 'f' );
const unsigned int box_TRAF = BOX( 't', 'r', 'a', 'f' );

const unsigned int box_TFDT = BOX( 't', 'f', 'd', 't' );
const unsigned int box_AVCN = BOX( 'a', 'v', 'c', 'n' );

const unsigned int ftyp_DASH = BOX( 'd', 'a', 's', 'h' );
const unsigned int ftyp_ISO6 = BOX( 'i', 's', 'o', '6' );
const unsigned int ftyp_ISO8 = BOX( 'i', 's', 'o', '8' );
const unsigned int ftyp_CMFS = BOX( 'c', 'm', 'f', 's' );

const unsigned int box_SDTP = BOX( 's', 'd', 't', 'p' );
const unsigned int box_STYP = BOX( 's', 't', 'y', 'p' );







__ALX_BEGIN_NAMESPACE


class MovieExtendsHeaderBox : public FullBox {
public:
    unsigned int fragment_duration_0;
    unsigned int fragment_duration;
    
public:
	V64(fragment_duration);
	

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrackExtendsBox : public FullBox {
public:
    unsigned int track_ID;
    unsigned int default_sample_description_index;
    unsigned int default_sample_duration;
    unsigned int default_sample_size;
    unsigned int default_sample_flags;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class MovieFragmentHeaderBox : public FullBox {
public:
    unsigned int sequence_number;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrackFragmentHeaderBox : public FullBox {
public:
    unsigned int track_ID;
    unsigned int base_data_offset_0;
    unsigned int base_data_offset;
    unsigned int sample_description_index;
    unsigned int default_sample_duration;
    unsigned int default_sample_size;
    unsigned int default_sample_flags;
    
public:
    V64(base_data_offset);
    
    TrackFragmentHeaderBox():
			  base_data_offset_0(0)
	        , base_data_offset(0)
	        , sample_description_index(0)
	        , default_sample_duration(0)
	        , default_sample_size(0)
	        , default_sample_flags(0)
    {
        
    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class trun_body {
public:
    unsigned int sample_duration;
    unsigned int sample_size;
    unsigned int sample_flags;
    unsigned int sample_composition_time_offset;
    public: virtual int get(IBitstream &var_bs, unsigned int flags);
    public: virtual int put(IBitstream &var_bs, unsigned int flags);
};

class TrackRunBox : public FullBox {
public:
    

private:
     std::vector<trun_body *> _samples;

     uint64_t _duration;

public:

      TrackRunBox():_duration(0)
      {}

      uint64_t get_duration(){return _duration;}
     
      void cleanup()
      {
          for(unsigned int i = 0; i <  _samples.size(); i++)
	      delete  _samples[i];
	 
	      _samples.clear();
      }
      
      void add(unsigned int s_duration,  unsigned int s_size, unsigned int s_flags, unsigned int s_composition_time_offset)
      {
		 trun_body * tp = new trun_body;
		             tp->sample_duration = s_duration;
		             tp->sample_size     = s_size;
		             tp->sample_flags    = s_flags;
		             tp->sample_composition_time_offset = s_composition_time_offset;
		             
		  _samples.push_back(tp);

          sample_count = ST_U32(_samples.size());

          _duration += s_duration;
      }
      
      

    unsigned int sample_count;
    int data_offset;
    unsigned int first_sample_flags;
    unsigned int __i;
    trun_body *_p_trun_body;
    
public:
	V32(sample_count);
	
	const trun_body & get_item(const int idx) const
	{
		return * _samples[idx];
	}
	
	virtual ~TrackRunBox(){cleanup();}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

struct RandomAccessPoint
{

     uint64_t time;
     uint64_t offset;
     uint64_t traf_number;
     uint64_t trun_number; 
     uint64_t sample_number;

};


class TrackFragmentRandomAccessBox : public FullBox {
public:
    
private:
		std::vector<RandomAccessPoint> _points;
protected:
virtual void index_item(
       uint64_t time
     , uint64_t offset
     , uint64_t traf_number 
     , uint64_t trun_number 
     , uint64_t sample_number
)
{
     RandomAccessPoint p = {time, offset, traf_number, trun_number, sample_number};
     _points.push_back(p);
}
private:

    unsigned int track_ID;
    unsigned int reserved;
    unsigned int length_size_of_traf_num;
    unsigned int length_size_of_trun_num;
    unsigned int length_size_of_sample_num;
    unsigned int number_of_entry;
    unsigned int i;
    unsigned int time_0;
    unsigned int time;
    unsigned int moof_offset_0;
    unsigned int moof_offset;
    unsigned int traf_number;
    unsigned int trun_number;
    unsigned int sample_number;
    
private:
      V64(time);
      V64(moof_offset);
public:
	  V32(track_ID);
	  V32(number_of_entry);
	  
	  uint64_t get_count(){return _points.size();}
	  RandomAccessPoint & get_point(int idx){return _points[idx];}
	  

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrackFragmentBaseMediaDecodeTimeBox : public FullBox {
public:
    unsigned int baseMediaDecodeTime_0;
    unsigned int baseMediaDecodeTime;
    
public:
	V64(baseMediaDecodeTime);
	

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrickPlayBoxRecord {
public:
    unsigned int pic_type;
    unsigned int dependency_level;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleDependencyTypeBoxRecord {
public:
    unsigned int is_leading;
    unsigned int sample_depends_on;
    unsigned int sample_is_depended_on;
    unsigned int sample_has_redundancy;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SSFLIVE_BODY {
public:
    unsigned int FragmentAbsoluteTime_0;
    unsigned int FragmentAbsoluteTime;
    unsigned int FragmentDuration_0;
    unsigned int FragmentDuration;
    

	unsigned int version;
    
public:
    V64(FragmentAbsoluteTime);
    V64(FragmentDuration);

    public: virtual int get(IBitstream &var_bs, unsigned int vers);
    public: virtual int put(IBitstream &var_bs, unsigned int vers);
};

__ALX_END_NAMESPACE


#endif /* ! var_mp4_fragments_h_ */
