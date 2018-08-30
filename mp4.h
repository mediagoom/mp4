/* @mediagen - appveyour message test -
 *
 * mp4.h
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

#ifndef var_mp4_h_
#define var_mp4_h_

// initial size of parsable arrays: 64


#include "media_parser.h"

#define V64(n) uint64_t get_ ## n  () const {if(1==version){return UI64(n ## _0, n);}else{return static_cast<uint64_t>(n);}}  \
            void set_ ## n  (const uint64_t rhs){n ## _0 = (rhs >> 32); n = static_cast<uint32_t>(rhs);}
#define S64(n) int64_t get_ ## n  () const {if(1==version){return I64(n ## _0, n);}else{return n;}}  \
            void set_ ## n  (const int64_t rhs){n ## _0 = (rhs >> 32); n = static_cast<int>(rhs);}
#define V32(n) unsigned int get_ ## n  () const {return n;} void set_ ## n  (const  unsigned int rhs){n = rhs;}
#define I2C(type, v) v[0] = 0x000000FF & type >> 24;v[1] = 0x000000FF & type >> 16;v[2] = 0x000000FF & type >> 8;v[3] = 0x000000FF & type ;v[4] = 0x00;

#define BOX(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))

//#include "mp4/mpeg4_odf.h"


#include "mpeg4_odf.h"
// pragma: array=256
// pragma: get



#define box_uuid BOX('u','u','i','d')
#define box_ftyp BOX('f','t','y','p')
#define box_avc1 BOX('a','v','c','1')
#define box_avcC BOX('a','v','c','C')
#define box_mp4a BOX('m','p','4','a')
#define box_esds BOX('e','s','d','s')
#define box_stsz BOX('s','t','s','z')
#define box_stz2 BOX('s','t','z','2')
#define box_stco BOX('s','t','c','o')
#define box_co64 BOX('c','o','6','4')
#define box_stsc BOX('s','t','s','c')
#define box_trak BOX('t','r','a','k')
#define box_tkhd BOX('t','k','h','d')
#define box_moov BOX('m','o','o','v')
#define box_mvhd BOX('m','v','h','d')
#define box_mdia BOX('m','d','i','a')
#define box_mdhd BOX('m','d','h','d')
#define box_minf BOX('m','i','n','f')
#define box_hdlr BOX('h','d','l','r')
#define box_vmhd BOX('v','m','h','d')
#define box_smhd BOX('s','m','h','d')
#define box_dinf BOX('d','i','n','f')
#define box_dref BOX('d','r','e','f')
#define box_stbl BOX('s','t','b','l')
#define box_stsd BOX('s','t','s','d')
#define box_mdat BOX('m','d','a','t')
#define box_free BOX('f','r','e','e')
#define box_btrt BOX('b','t','r','t')

#define box_stts BOX('s','t','t','s')
#define box_ctts BOX('c','t','t','s')
#define box_stss BOX('s','t','s','s')
#define box_edts BOX('e','d','t','s')
#define box_elst BOX('e','l','s','t')
#define box_iods BOX('i','o','d','s')

#define box_pasp BOX('p','a','s','p')
#define box_clap BOX('c','a','a','p')
#define box_sidx BOX('s','i','d','x')

#define ftyp_isom BOX('i','s','o','m')
#define ftyp_iso2 BOX('i','s','o','2')
#define ftyp_avc1 BOX('a','v','c','1')
#define ftyp_mp41 BOX('m','p','4','1')


#define box_url  BOX('u', 'r', 'l', ' ')
#define box_xml  BOX('x', 'm', 'l', ' ')
#define box_meta BOX('m', 'e', 't', 'a')







__ALX_BEGIN_NAMESPACE

extern const unsigned int BOX_UUID;
extern const unsigned int handler_vide;
extern const unsigned int handler_soun;

class Box {
public:
    
private:

    unsigned int size;
    unsigned int type;
    unsigned int x;
    unsigned int y;
    unsigned char byte_01;
    unsigned char byte_02;
    unsigned char byte_03;
    unsigned char byte_04;
    unsigned char byte_05;
    unsigned char byte_06;
    unsigned char byte_07;
    unsigned char byte_08;
    unsigned char byte_09;
    unsigned char byte_10;
    unsigned char byte_11;
    unsigned char byte_12;
    unsigned char byte_13;
    unsigned char byte_14;
    unsigned char byte_15;
    unsigned char byte_16;
    
      TCHAR _stype[5];
public:
      Box()
      {
        
      }
      
      const unsigned char * guid() const {return &byte_01;}
            unsigned char * direct_guid() {return &byte_01;}
      
      const TCHAR* get_type_string() const
      { 
         return reinterpret_cast<const TCHAR*>(_stype);
      }
      
      uint64_t get_size() const
      {
         uint64_t s = size;

         if(1 == s)
         {
            s = UI64(x, y);
         }

	  if(type == BOX_UUID)
	  	s -= 16; 
         
         return s;
      }
      
      V32(type);
   
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class FullBox {
public:
    
protected:

    unsigned int version;
    unsigned int flags;
    
public:
	V32(version);
	V32(flags);

    FullBox():version(0), flags(0){}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class PixelAspectRatioBox {
public:
    unsigned int hSpacing;
    unsigned int vSpacing;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class CleanApertureBox {
public:
    unsigned int cleanApertureWidthN;
    unsigned int cleanApertureWidthD;
    unsigned int cleanApertureHeightN;
    unsigned int cleanApertureHeightD;
    unsigned int horizOffN;
    unsigned int horizOffD;
    unsigned int vertOffN;
    unsigned int vertOffD;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class MovieHeaderBox : public FullBox {
public:
    
private:

    unsigned int creation_time_0;
    unsigned int creation_time;
    unsigned int modification_time_0;
    unsigned int modification_time;
    unsigned int timescale;
    unsigned int duration_0;
    unsigned int duration;
    int rate;
    int volume;
    unsigned int bit_reserved;
    unsigned int reserved;
    int matrix_1;
    int matrix_2;
    int matrix_3;
    int matrix_4;
    int matrix_5;
    int matrix_6;
    int matrix_7;
    int matrix_8;
    int matrix_9;
    unsigned int pre_defined;
    unsigned int next_track_ID;
    
public:
    V64(creation_time);
	V64(modification_time);
	V64(duration);
	V32(timescale);
	V32(rate);
	V32(volume);
	V32(next_track_ID);
	
	uint64_t get_duration_hns()const{return (1000UL * 10000UL * get_duration()) / get_timescale() ;}

     MovieHeaderBox():
         matrix_1(0x00010000)
       , matrix_2(0)
       , matrix_3(0)
       , matrix_4(0)
       , matrix_5(0x00010000)
       , matrix_6(0)
       , matrix_7(0)
       , matrix_8(0)
       , matrix_9(0x40000000)
       , rate(0x00010000) // typically 1.0
       , volume(0x0100)        
     {
     }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrackHeaderBox : public FullBox {
public:
    
private:

    unsigned int creation_time_0;
    unsigned int creation_time;
    unsigned int modification_time_0;
    unsigned int modification_time;
    unsigned int track_ID;
    unsigned int reserved;
    unsigned int duration_0;
    unsigned int duration;
    int layer;
    int alternate_group;
    int volume;
    int matrix_1;
    int matrix_2;
    int matrix_3;
    int matrix_4;
    int matrix_5;
    int matrix_6;
    int matrix_7;
    int matrix_8;
    int matrix_9;
    unsigned int width;
    unsigned int width_coma;
    unsigned int height;
    unsigned int height_coma;
    
public:
    V64(creation_time);
	V64(modification_time);
	V64(duration);
	V32(width);
	V32(height);
	V32(volume);
	V32(track_ID);

	TrackHeaderBox():
	   layer(0)
         , alternate_group(0)
       , matrix_1(0x00010000)
       , matrix_2(0)
       , matrix_3(0)
       , matrix_4(0)
       , matrix_5(0x00010000)
       , matrix_6(0)
       , matrix_7(0)
       , matrix_8(0)
       , matrix_9(0x40000000)
       , duration(0)
       , width(0)
       , width_coma(0)
       , height(0)
       , height_coma(0)
	{
	}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class MediaHeaderBox : public FullBox {
public:
    
private:
        TCHAR _lang[4];

    unsigned int creation_time_0;
    unsigned int creation_time;
    unsigned int modification_time_0;
    unsigned int modification_time;
    unsigned int timescale;
    unsigned int duration_0;
    unsigned int duration;
    unsigned int pad;
    
public:

    unsigned int lang_1;
    unsigned int lang_2;
    unsigned int lang_3;
    unsigned int pre_defined;
    
public:
    V64(creation_time);
	V64(modification_time);
	V64(duration);
	V32(timescale);
/*	
	lang += 0x60 = ascci

*/
    TCHAR * get_lang(){_lang[0]=lang_1+0x60;_lang[1]=lang_2+0x60;_lang[2]=lang_3+0x60;_lang[3]='\0';return _lang;}
    
    void set_lang(TCHAR * lang){lang_1=lang[0]-0x60;lang_2=lang[1]-0x60;lang_3=lang[2]-0x60;}


    uint64_t get_duration_hns()const {return (1000UL * 10000UL * get_duration()) / get_timescale() ;}

    MediaHeaderBox():
      lang_1(21)
    , lang_2(14)
    , lang_3(4)
    {}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class HandlerBox : public FullBox {
public:
    unsigned int pre_defined;
    unsigned int handler_type;
    unsigned int reserved;
    TCHAR desc[1024];
      TCHAR htype[5];
      unsigned int __body_size;
private:
    
    unsigned int __x;
    unsigned int __max;
    char __name;
    
public:
    HandlerBox(unsigned int boxsize){ _ASSERTE(32 <= boxsize); __body_size = boxsize - 32;}
    HandlerBox():reserved(0)
    {
desc[0] = 'F';
desc[1] = 'O';
desc[2] = 'U';
desc[3] = 'N';
desc[4] = 'D';
desc[5] = 'A';
desc[6] = 'T';
desc[7] = 'I';
desc[8] = 'O';
desc[9] = 'N';
desc[10] = ' ';
desc[11] = 'M';
desc[12] = 'E';
desc[13] = 'D';
desc[14] = 'I';
desc[15] = 'A';
desc[16] = ' ';
desc[17] = 'H';
desc[18] = 'A';
desc[19] = 'N';
desc[20] = 'D';
desc[21] = 'L';
desc[22] = 'E';
desc[23] = 'R';
desc[24] = '\0';
desc[25] = '\0';
desc[26] = '\0';

__body_size = 25;
       
    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class DataReferenceBox : public FullBox {
public:
    unsigned int entry_count;
    
    DataReferenceBox():entry_count(0)
    {
       //flags = 0x000001;//data in the file
    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleDescriptionBox : public FullBox {
public:
    unsigned int entry_count;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleEntry {
public:
    unsigned int reserved;
    int data_reference_index;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class VisualSampleEntry : public SampleEntry {
public:
    unsigned int pre_defined;
    unsigned int reserved;
    unsigned int width;
    unsigned int height;
    unsigned int horizresolution;
    unsigned int vertresolution;
    unsigned int frame_count;
    unsigned int size;
    unsigned int idx;
    unsigned int _string_array_size;
    char compressorname[256];
    unsigned int depth;
    int pre_defined16;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class AVCDecoderConfigurationRecord {
public:
    
	
protected:
	virtual void add_sequence_parameter_set(const unsigned char * body, unsigned int size){}
	virtual void add_picture_parameter_set (const unsigned char * body, unsigned int size){}
public:

    unsigned int configurationVersion;
    unsigned int AVCProfileIndication;
    unsigned int profile_compatibility;
    unsigned int AVCLevelIndication;
    unsigned int reserved;
    unsigned int lengthSizeMinusOne;
    unsigned int numOfSequenceParameterSets;
    unsigned int __idx;
    unsigned int __idy;
    unsigned int sequenceParameterSetLength[256];
    unsigned char sequenceParameterSetNALUnit[256];
    unsigned int numOfPictureParameterSets;
    unsigned int pictureParameterSetLength[256];
    unsigned char pictureParameterSetNALUnit[256];
    
public:
      const BYTE* get_sequence(unsigned int idx = 0) const {_ASSERTE(0==idx);return sequenceParameterSetNALUnit;}
      const unsigned int get_sequence_size(unsigned int idx = 0) const {_ASSERTE(0==idx);return  sequenceParameterSetLength[idx];}
      const unsigned int get_sequence_count() const {return numOfSequenceParameterSets;}



      const BYTE* get_picture(unsigned int idx = 0) const {_ASSERTE(0==idx);return pictureParameterSetNALUnit;}
      const unsigned int get_picture_size(unsigned int idx = 0) const {_ASSERTE(0==idx);return  pictureParameterSetLength[idx];}
      const unsigned int get_picture_count() const {return numOfPictureParameterSets;}
      
      unsigned int get_nal_length_size() const {return lengthSizeMinusOne + 1;}

      void set_sps(const BYTE * source, const int size)
      {
         numOfSequenceParameterSets    = 1;
	 sequenceParameterSetLength[0] = size;

	 for(int ix = 0; ix < size; ix++)
	      sequenceParameterSetNALUnit[ix] = source[ix];
	       

      }

      void set_pps(const BYTE * source, const int size)
      {
         numOfPictureParameterSets    = 1;
	 pictureParameterSetLength[0] = size;

	 for(int ix = 0; ix < size; ix++)
	      pictureParameterSetNALUnit[ix] = source[ix];
	       

      }
      
      

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class BitRateBox {
public:
    unsigned int bufferSizeDB;
    unsigned int maxBitrate;
    unsigned int avgBitrate;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TimeToSampleBox : public FullBox {
public:
    unsigned int entry_count;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class AudioSampleEntry : public SampleEntry {
public:
    unsigned int reserved;
    unsigned int channelcount;
    unsigned int samplesize;
    unsigned int pre_defined;
    unsigned int reserved16;
    unsigned int samplerate;
    
public:
	V32(channelcount);
	V32(samplesize);
    unsigned int get_samplerate() const {return (samplerate >> 16);}
    void set_samplerate(const unsigned int sr){samplerate = (sr << 16);}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class EditListBoxItem {
public:
    
   uint64_t _segment_duration;
            int64_t _media_time;
   short    _media_rate_integer;
   short    _media_rate_fraction;

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class EditListBox : public FullBox {
public:
    
private:
        std::vector<EditListBoxItem*> _items;

    unsigned int __entry_count;
    unsigned int __i;
    unsigned int segment_duration_0;
    unsigned int segment_duration;
    int media_time_0;
    int media_time;
    int media_rate_integer;
    int media_rate_fraction;
    
      V64(segment_duration);
      S64(media_time);
      void cleanup()
      {
          for(size_t i = 0; i <  _items.size(); i++)
			delete  _items[i];
	 
	   _items.clear();
      }
public:
      virtual ~EditListBox()
      {
        cleanup();
      }

      size_t count() const {_ASSERTE(__entry_count == _items.size());return _items.size();}
      const EditListBoxItem& entry(uint32_t idx) const{_ASSERTE(idx < _items.size());return *_items[idx];}
      
      void add_item(
       	  const uint64_t segment_duration
	, const          int64_t media_time
	, const uint64_t u_media_rate_integer
	, const uint64_t u_media_rate_fraction = 0
	)
      {
        EditListBoxItem * p     = new EditListBoxItem;
	p->_segment_duration    = segment_duration;
	p->_media_time          = media_time;
	p->_media_rate_integer  = static_cast<short>(u_media_rate_integer);
	p->_media_rate_fraction = static_cast<short>(u_media_rate_fraction);

	_items.push_back(p);
      }


    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class FileTypeBox {
public:
    
private:
     std::vector<unsigned int> _items;
     unsigned int _size;
     

    unsigned int major_brand;
    unsigned int minor_version;
    unsigned int __size;
    unsigned int compatible_brand;
    
public:
    FileTypeBox():_size(0){}
    FileTypeBox(unsigned int size):_size(size - 16){}
    V32(major_brand);
    V32(minor_version);

    size_t count() const {return _items.size();}
    unsigned int get_brand(unsigned int idx) const {_ASSERTE(_items.size() > idx); return _items[idx];}
    void add_brand(unsigned int brand){_items.push_back(brand);}
    
    void clear_brands()
    {
		_items.clear();
    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SoundMediaHeaderBox : public FullBox {
public:
    int balance;
    unsigned int reserved;
    
   SoundMediaHeaderBox():
     balance(0)
   ,reserved(0)
   {}
      

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class VideoMediaHeaderBox : public FullBox {
public:
    unsigned int graphicsmode;
    unsigned int opcolor1;
    unsigned int opcolor2;
    unsigned int opcolor3;
    
   VideoMediaHeaderBox():
     graphicsmode(0)
   , opcolor1(0)
   , opcolor2(0)
   , opcolor3(0)
   {}
      

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SegmentIndexBox : public FullBox {
public:
    unsigned int reference_ID;
    unsigned int timescale;
    unsigned int earliest_presentation_time;
    unsigned int first_offset;
    unsigned int earliest_presentation_time_0;
    unsigned int first_offset_0;
    unsigned int reserved;
    unsigned int reference_count;
    unsigned int i;
    unsigned int reference_type[256];
    unsigned int referenced_size[256];
    unsigned int subsegment_duration[256];
    unsigned int starts_with_SAP[256];
    unsigned int SAP_type[256];
    unsigned int SAP_delta_time[256];
    
public:
	V64(earliest_presentation_time)
	V64(first_offset)

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class XmlBox : public FullBox {
public:
    
      TCHAR *       _p_xml;
      size_t        __body_size;
private:
    
    unsigned int __x;
    unsigned int __max;
    char __name;
    
    void init()
    {
        _p_xml = new TCHAR[__body_size + 1];
      memset(_p_xml, 0,  __body_size * sizeof(TCHAR));
    }
public:
    XmlBox(unsigned int boxsize):_p_xml(NULL)
    { _ASSERTE(12 <= boxsize); __body_size = boxsize - 12;
      init();
    }
    ~XmlBox(){if(_p_xml)delete[] _p_xml;}
    XmlBox(const TCHAR * pszXml):_p_xml(NULL)
    {
       __body_size = _tcslen(pszXml);
       init();
       ::memcpy(_p_xml, pszXml, __body_size * sizeof(TCHAR));
    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_mp4_h_ */
