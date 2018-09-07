/* @mediagen - catch api call error -
 *
 * mpeg4_odf.h
 * 
 * This file was automatically generated
 * from the source file:
 *     'mpeg4_odf.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#ifndef var_mpeg4_odf_h_
#define var_mpeg4_odf_h_

// initial size of parsable arrays: 64


#include "media_parser.h"
#include <vector>

// pragma: array=256
// pragma: get

__ALX_BEGIN_NAMESPACE

extern const unsigned int TAG_RESERVED;
extern const unsigned int TAG_OD;
extern const unsigned int TAG_IOD;
extern const unsigned int TAG_ESD;
extern const unsigned int TAG_DCD;
extern const unsigned int TAG_DSI;
extern const unsigned int TAG_SLC;
extern const unsigned int TAG_CI;
extern const unsigned int TAG_SCI;
extern const unsigned int TAG_IPI_PTR;
extern const unsigned int TAG_IPMP_PTR;
extern const unsigned int TAG_IPMP;
extern const unsigned int TAG_QOS;
extern const unsigned int TAG_REG;
extern const unsigned int TAG_ESD_INC;
extern const unsigned int TAG_ESD_REF;
extern const unsigned int TAG_ISOM_IOD;
extern const unsigned int TAG_ISOM_OD;
extern const unsigned int TAG_ISOM_IPI_PTR;
extern const unsigned int TAG_EXT_PL;
extern const unsigned int TAG_PL_IDX;
extern const unsigned int TAG_ISO_BEGIN;
extern const unsigned int TAG_ISO_END;
extern const unsigned int TAG_CC;
extern const unsigned int TAG_KW;
extern const unsigned int TAG_RATING;
extern const unsigned int TAG_LANG;
extern const unsigned int TAG_SHORT_TEXT;
extern const unsigned int TAG_TEXT;
extern const unsigned int TAG_CC_NAME;
extern const unsigned int TAG_CC_DATE;
extern const unsigned int TAG_OCI_NAME;
extern const unsigned int TAG_OCI_DATE;
extern const unsigned int TAG_SMPTE;
extern const unsigned int TAG_SEGMENT;
extern const unsigned int TAG_MEDIATIME;
extern const unsigned int TAG_IPMP_TL;
extern const unsigned int TAG_IPMP_TOOL;
extern const unsigned int TAG_ISO_RES_BEGIN;
extern const unsigned int TAG_ISO_RES_END;

class descriptor {
public:
    unsigned int tag;
    
   int  __v_length; 
   bool _reading;

  

    int __reading;
    int __sizeHeader;
    int length;
    unsigned int size;
    unsigned char vals[256];
    unsigned int __blength;
    
public:
    descriptor():_reading(true){}
    descriptor(bool read_mode):_reading(read_mode){}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class language_descriptor : public descriptor {
public:
    unsigned int languageCode;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class extension_descriptor : public descriptor {
public:
    
private:
     BYTE * _row_memory;
   
    int _byte_size;
    unsigned int length2;
    int __idx;
    unsigned int descriptor_byte;
    
      void cleanup(){if(_row_memory)delete[] _row_memory;_row_memory=NULL;}
public:
      extension_descriptor():_row_memory(NULL){}
      
      virtual ~extension_descriptor(){cleanup();}
      unsigned int get_length() const {return length;}
      const BYTE* get_descriptor() const {return _row_memory;}
      void set_descriptor(const BYTE* source, const unsigned size)
      {
          _ASSERTE(size < 254);
          _ASSERTE(NULL ==  _row_memory);
	  length = size;
	   _byte_size = size;
	  _row_memory = new BYTE[_byte_size]; 
	  memcpy(_row_memory, source, _byte_size);
      }
   
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class DecoderConfigDescriptor : public descriptor {
public:
    
    std::vector<extension_descriptor *> _extension_descriptors;

    unsigned int objectProfileIndication;
    unsigned int streamType;
    unsigned int upStream;
    unsigned int reserved;
    unsigned int bufferSizeDB;
    unsigned int maxBitrate;
    unsigned int avgBitrate;
    extension_descriptor *p_ext;
    
      
public:
    
    
    void cleanup()
    {
       for(unsigned int i = 0; i < _extension_descriptors.size(); i++)
          delete _extension_descriptors[i];
          
       _extension_descriptors.clear();

    }
    
    virtual ~DecoderConfigDescriptor(){cleanup();}

    void add_extension(const BYTE* source, const unsigned size)
    {
    	_reading = false;
    	extension_descriptor * pe = new extension_descriptor;
	                       pe->_reading = false;
			       pe->tag = TAG_DSI;
	                       pe->set_descriptor(source, size);
	
	_extension_descriptors.push_back(pe);

    }

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class SLConfigDescriptor : public descriptor {
public:
    unsigned int predefined;
    unsigned int useAccessUnitStartFlag;
    unsigned int useAccessUnitEndFlag;
    unsigned int useRandomAccessPointFlag;
    unsigned int usePaddingFlag;
    unsigned int useTimeStampsFlag;
    unsigned int useWallClockTimeStampFlag;
    unsigned int useIdleFlag;
    unsigned int durationFlag;
    unsigned int timeStampResolution;
    unsigned int OCRResolution;
    unsigned int timeStampLength;
    unsigned int OCRLength;
    unsigned int AU_Length;
    unsigned int instantBitrateLength;
    unsigned int degradationPriorityLength;
    unsigned int seqNumLength;
    unsigned int timeScale;
    unsigned int accessUnitDuration;
    unsigned int compositionUnitDuration;
    unsigned int wallClockTimeStamp_1;
    unsigned int wallClockTimeStamp_2;
    unsigned int startDecodingTimeStamp;
    unsigned int startCompositionTimeStamp;
    unsigned int OCRstreamFlag;
    unsigned int reserved;
    unsigned int OCR_ES_Id;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class IP_IdentificationDataSet : public descriptor {
public:
    unsigned int i;
    unsigned int compatibility;
    unsigned int contentTypeFlag;
    unsigned int contentIdentifierFlag;
    unsigned int supplementaryContentIdentifierCount;
    unsigned int contentType;
    unsigned int contentIdentifierType;
    unsigned int contentIdentifierLength;
    unsigned int contentIdentifier[256];
    unsigned int languageCode;
    unsigned int supplementaryContentIdentifierTitleLength;
    unsigned int supplementaryContentIdentifierTitle[256][256];
    unsigned int supplementaryContentIdentifierValueLength;
    unsigned int supplementaryContentIdentifierValue[256][256];
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class IPI_DescPointer : public descriptor {
public:
    unsigned int IPI_ES_Id;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class QoS_Descriptor : public descriptor {
public:
    unsigned int i;
    unsigned int x;
    unsigned int predefined;
    unsigned int QoS_QualifierCount;
    unsigned int QoS_QualifierTag[256];
    unsigned int QoS_QualifierLength[256];
    unsigned int QoS_QualifierData[256][256];
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class ES_Descriptor : public descriptor {
public:
    
    std::vector<extension_descriptor *> _extension_descriptors;

    unsigned int ES_ID;
    unsigned int streamDependenceFlag;
    unsigned int URL_Flag;
    unsigned int OCR_Flag;
    unsigned int streamPriority;
    unsigned int dependsOn_ES_ID;
    unsigned int s_size;
    unsigned int URLstring[256];
    unsigned int OCRESID;
    extension_descriptor *p_ext;
    language_descriptor *p_lang;
    DecoderConfigDescriptor *p_decoder_config_descriptor;
    SLConfigDescriptor *p_sl_config_descriptor;
    IPI_DescPointer *p_ipi_desc_pointer;
    IP_IdentificationDataSet *p_ip_idset;
    QoS_Descriptor *p_qos;
    
      
public:
    
    ES_Descriptor():
      p_lang(NULL)
    , p_decoder_config_descriptor(NULL)
    , p_sl_config_descriptor(NULL)
    , p_ipi_desc_pointer(NULL)
    , p_ip_idset(NULL)
    , p_qos(NULL)
    {}

    void cleanup()
    {
       for(unsigned int i = 0; i < _extension_descriptors.size(); i++)
          delete _extension_descriptors[i];
          
       _extension_descriptors.clear();

       if(p_lang)
          delete p_lang;

       p_lang = NULL;

       if(p_decoder_config_descriptor)
          delete p_decoder_config_descriptor;

      p_decoder_config_descriptor = NULL;

      if(p_sl_config_descriptor)
        delete p_sl_config_descriptor;

      p_sl_config_descriptor = NULL;

      if(p_ipi_desc_pointer)
        delete p_ipi_desc_pointer;

      p_ipi_desc_pointer = NULL;

      if(p_ip_idset)
         delete  p_ip_idset;

       p_ip_idset = NULL;

      if(p_qos)
        delete p_qos;

      p_qos = NULL;

    }
    
    virtual ~ES_Descriptor(){cleanup();}

    void set_extension(const BYTE* source
                     , const unsigned size
			, const unsigned int objectProfileIndication
			, const unsigned int streamType
			, const unsigned int upStream
			, const unsigned int bufferSizeDB
			, const unsigned int maxBitrate
			, const unsigned int avgBitrate
		      )
    {
    	_reading = false;

	int descriptor_size = 0;

	p_decoder_config_descriptor         = new DecoderConfigDescriptor;
	p_decoder_config_descriptor->tag    = TAG_DCD;
	p_decoder_config_descriptor->length = descriptor_size + 13 + 5 + size; 
	p_decoder_config_descriptor->add_extension(source, size);

	p_decoder_config_descriptor->objectProfileIndication = objectProfileIndication;
	p_decoder_config_descriptor->streamType = streamType;
	p_decoder_config_descriptor->upStream = upStream;
	p_decoder_config_descriptor->bufferSizeDB = bufferSizeDB;
	p_decoder_config_descriptor->maxBitrate = maxBitrate;
	p_decoder_config_descriptor->avgBitrate = avgBitrate;
	

	p_sl_config_descriptor = new SLConfigDescriptor;
	p_sl_config_descriptor->tag = TAG_SLC;
	p_sl_config_descriptor->length = descriptor_size + 1;
	p_sl_config_descriptor->predefined = 0x02;//0xFFFF;
	p_sl_config_descriptor->_reading = false;

	tag = TAG_ESD;
	length = 3 + p_sl_config_descriptor->length + p_decoder_config_descriptor->length + 10;

	ES_ID = 0;
	streamDependenceFlag = 0;
	URL_Flag =  0;
	OCR_Flag =  0; 
	streamPriority = 0;
	
    }

    
    

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class OCIGenericDescriptor : public extension_descriptor {
public:
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class InitialObjectDescriptor : public descriptor {
public:
    
private:
    std::vector<extension_descriptor *> _extension_descriptors;
    std::vector<ES_Descriptor *> _es_descriptors;
    std::vector<OCIGenericDescriptor*> _oci_descriptors;

    unsigned int ObjectDescriptorID;
    unsigned int URL_Flag;
    unsigned int includeInlineProfilesFlag;
    unsigned int reserved;
    unsigned int s_size;
    unsigned int URLstring[256];
    unsigned int OD;
    unsigned int sceneProfile;
    unsigned int audioProfile;
    unsigned int visualProfile;
    unsigned int graphicsProfile;
    extension_descriptor *p_ext;
    OCIGenericDescriptor *p_oci;
    ES_Descriptor *p_esd;
    
public:


void cleanup()
    {
       for(unsigned int i = 0; i < _extension_descriptors.size(); i++)
          delete _extension_descriptors[i];
          
       _extension_descriptors.clear();

        for(unsigned int i = 0; i <  _es_descriptors.size(); i++)
          delete  _es_descriptors[i];
          
       _es_descriptors.clear();

        for(unsigned int i = 0; i < _oci_descriptors.size(); i++)
          delete _oci_descriptors[i];
          
       _oci_descriptors.clear();


    }

     InitialObjectDescriptor(){}
     virtual ~ InitialObjectDescriptor(){cleanup();}

    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_mpeg4_odf_h_ */
