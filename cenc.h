/* @mediagen - remove  test_multiple_bitrate.py from make test -
 *
 * cenc.h
 * 
 * This file was automatically generated
 * from the source file:
 *     'cenc.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#ifndef var_cenc_h_
#define var_cenc_h_

// initial size of parsable arrays: 64

#include "mp4.h"

__ALX_BEGIN_NAMESPACE

// pragma: array=256

#include "media_parser.h"

#define box_sinf BOX('s','i','n','f')
#define box_frma BOX('f','r','m','a')
#define box_schm BOX('s','c','h','m')
#define box_schi BOX('s','c','h','i')
#define box_encv BOX('e', 'n', 'c', 'v')
#define box_enca BOX('e', 'n', 'c', 'a')

#define box_saio BOX('s', 'a', 'i', 'o')
#define box_saiz BOX('s', 'a', 'i', 'z')

#define box_senc BOX('s', 'e', 'n', 'c')
#define box_tenc BOX('t', 'e', 'n', 'c')
#define box_pssh BOX('p', 's', 's', 'h')

#define box_cenc BOX('c', 'e', 'n', 'c')

#define CENC
#define BLOCK_LEN 16 
#define ID_LEN 16
#define KEY_LEN 16



class AssetInformationBox {
public:
    int profile_version;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class OriginalFormatBox {
public:
    unsigned int data_format;
    
      TCHAR _stype[5];
  
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SchemeTypeBox : public FullBox {
public:
    unsigned int scheme_type;
    unsigned int scheme_version;
    unsigned int scheme_uri;
    
      TCHAR _stype[5];
  
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class TrackEncryptionBox : public FullBox {
public:
    unsigned int reserved;
    unsigned int reserved2;
    unsigned int default_crypt_byte_block;
    unsigned int default_skip_byte_block;
    unsigned int default_isProtected;
    unsigned int default_Per_Sample_IV_Size;
    unsigned char default_KID;
    unsigned char default_KID_0;
    unsigned char default_KID_1;
    unsigned char default_KID_2;
    unsigned char default_KID_3;
    unsigned char default_KID_4;
    unsigned char default_KID_5;
    unsigned char default_KID_6;
    unsigned char default_KID_7;
    unsigned char default_KID_8;
    unsigned char default_KID_9;
    unsigned char default_KID_10;
    unsigned char default_KID_11;
    unsigned char default_KID_12;
    unsigned char default_KID_13;
    unsigned char default_KID_14;
    unsigned int default_constant_IV_size;
    unsigned char default_constant_IV[256];
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleEncryptionInitializationVector64 {
public:
    unsigned char InitializationVector_0;
    unsigned char InitializationVector_1;
    unsigned char InitializationVector_2;
    unsigned char InitializationVector_3;
    unsigned char InitializationVector_4;
    unsigned char InitializationVector_5;
    unsigned char InitializationVector_6;
    unsigned char InitializationVector_7;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SubSampleEncryptionBox {
public:
    unsigned int BytesOfClearData;
    unsigned int BytesOfProtectedData;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SingleEncryptionBox {
public:
    
	std::vector<SubSampleEncryptionBox *> _sub_samples;
	
	SingleEncryptionBox():
		subsample_count(0)
		, init_vector(NULL)
	{}
	
	virtual ~SingleEncryptionBox()
	{
	   for(unsigned int i = 0; i < _sub_samples.size(); i++)
	   {
		  delete _sub_samples[i];
	   }
	   
	   _sub_samples.clear();
	   
	   delete init_vector;
	}

    SampleEncryptionInitializationVector64 *init_vector;
    unsigned int subsample_count;
    SubSampleEncryptionBox *_p_sub_sample;
    public: virtual int get(IBitstream &var_bs, int ff);
    public: virtual int put(IBitstream &var_bs, int ff);
};

class SampleEncryptionBox : public FullBox {
public:
    
	std::vector<SingleEncryptionBox *> _samples;
	
	void cleanup()
	{
	   for(unsigned int i = 0; i < _samples.size(); i++)
	   {
		  delete _samples[i];
	   }
	   
	   _samples.clear();
	}
	
	~SampleEncryptionBox()
	{
		cleanup();
	}
	

    unsigned int sample_count;
    unsigned int i;
    SingleEncryptionBox *_p_single_box;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleAuxiliaryInformationSizesBox : public FullBox {
public:
    
	std::vector<int> _samples_info_size;

    unsigned int aux_info_type;
    unsigned int aux_info_type_parameter;
    unsigned int default_sample_info_size;
    unsigned int sample_count;
    unsigned int sample_info_size;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleAuxiliaryInformationOffsetsBox : public FullBox {
public:
    
	  V64(offset);
	  
	  std::vector<uint64_t> _samples_offset;

    unsigned int aux_info_type;
    unsigned int aux_info_type_parameter;
    unsigned int entry_count;
    unsigned int i;
    unsigned int offset;
    unsigned int offset_0;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ProtectionSystemSpecificHeaderBox : public FullBox {
public:
    
	  unsigned char *  _p_data;
	  
	  ~ProtectionSystemSpecificHeaderBox()
	  {
		delete[] _p_data;
	  }

    unsigned char SystemID;
    unsigned char SystemID_1;
    unsigned char SystemID_2;
    unsigned char SystemID_3;
    unsigned char SystemID_4;
    unsigned char SystemID_5;
    unsigned char SystemID_6;
    unsigned char SystemID_7;
    unsigned char SystemID_8;
    unsigned char SystemID_9;
    unsigned char SystemID_10;
    unsigned char SystemID_11;
    unsigned char SystemID_12;
    unsigned char SystemID_13;
    unsigned char SystemID_14;
    unsigned char SystemID_15;
    unsigned char _end;
    unsigned int KID_count;
    unsigned char KID;
    unsigned char KID_1;
    unsigned char KID_2;
    unsigned char KID_3;
    unsigned char KID_4;
    unsigned char KID_5;
    unsigned char KID_6;
    unsigned char KID_7;
    unsigned char KID_8;
    unsigned char KID_9;
    unsigned char KID_10;
    unsigned char KID_11;
    unsigned char KID_12;
    unsigned char KID_13;
    unsigned char KID_14;
    unsigned char KID_15;
    unsigned int DataSize;
    unsigned int k;
    unsigned char Data;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleToGroupBoxItem {
public:
    unsigned int sample_count;
    unsigned int group_description_index;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleToGroupBox : public FullBox {
public:
    
	std::vector<SampleToGroupBoxItem*> _samples;
	  
	~SampleToGroupBox()
	{
	   for(unsigned int i = 0; i < _samples.size(); i++)
	   {
		  delete _samples[i];
	   }
	   
	   _samples.clear();
	}

    unsigned int grouping_type;
    unsigned int grouping_type_parameter;
    unsigned int entry_count;
    unsigned int i;
    SampleToGroupBoxItem *_item;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class CencSampleEncryptionInformationGroupEntry {
public:
    
	CencSampleEncryptionInformationGroupEntry()
		: constant_IV_size(0)
	{}

    unsigned int reserved;
    unsigned int crypt_byte_block;
    unsigned int skip_byte_block;
    unsigned int isProtected;
    unsigned int Per_Sample_IV_Size;
    unsigned char KID;
    unsigned char KID_1;
    unsigned char KID_2;
    unsigned char KID_3;
    unsigned char KID_4;
    unsigned char KID_5;
    unsigned char KID_6;
    unsigned char KID_7;
    unsigned char KID_8;
    unsigned char KID_9;
    unsigned char KID_10;
    unsigned char KID_11;
    unsigned char KID_12;
    unsigned char KID_13;
    unsigned char KID_14;
    unsigned char KID_15;
    unsigned int constant_IV_size;
    unsigned char constant_IV;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SampleGroupDescriptionBox : public FullBox {
public:
    
	SampleGroupDescriptionBox():_seig(NULL){}
	~SampleGroupDescriptionBox(){delete _seig;}

    unsigned int grouping_type;
    unsigned int default_length;
    unsigned int entry_count;
    unsigned int i;
    unsigned int description_length;
    CencSampleEncryptionInformationGroupEntry *_seig;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_cenc_h_ */
