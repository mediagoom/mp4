/* @mediagen - Re-enable win builds -
 *
 * mpeg4_odf.cpp
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

#include "stdafx.h"
#include <TBitstream.h>
#include "mpeg4_odf.h"


__ALX_BEGIN_NAMESPACE
const unsigned int TAG_RESERVED = 0;
const unsigned int TAG_OD = 1;
const unsigned int TAG_IOD = 2;
const unsigned int TAG_ESD = 3;
const unsigned int TAG_DCD = 4;
const unsigned int TAG_DSI = 5;
const unsigned int TAG_SLC = 6;
const unsigned int TAG_CI = 7;
const unsigned int TAG_SCI = 8;
const unsigned int TAG_IPI_PTR = 9;
const unsigned int TAG_IPMP_PTR = 10;
const unsigned int TAG_IPMP = 11;
const unsigned int TAG_QOS = 12;
const unsigned int TAG_REG = 13;
const unsigned int TAG_ESD_INC = 14;
const unsigned int TAG_ESD_REF = 15;
const unsigned int TAG_ISOM_IOD = 16;
const unsigned int TAG_ISOM_OD = 17;
const unsigned int TAG_ISOM_IPI_PTR = 18;
const unsigned int TAG_EXT_PL = 19;
const unsigned int TAG_PL_IDX = 20;
const unsigned int TAG_ISO_BEGIN = 21;
const unsigned int TAG_ISO_END = 63;
const unsigned int TAG_CC = 64;
const unsigned int TAG_KW = 65;
const unsigned int TAG_RATING = 66;
const unsigned int TAG_LANG = 67;
const unsigned int TAG_SHORT_TEXT = 68;
const unsigned int TAG_TEXT = 69;
const unsigned int TAG_CC_NAME = 70;
const unsigned int TAG_CC_DATE = 71;
const unsigned int TAG_OCI_NAME = 72;
const unsigned int TAG_OCI_DATE = 73;
const unsigned int TAG_SMPTE = 74;
const unsigned int TAG_SEGMENT = 75;
const unsigned int TAG_MEDIATIME = 76;
const unsigned int TAG_IPMP_TL = 96;
const unsigned int TAG_IPMP_TOOL = 97;
const unsigned int TAG_ISO_RES_BEGIN = 98;
const unsigned int TAG_ISO_RES_END = 191;

int descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end;
    var_bs.align(8);
    tag = var_bs.getbits(8);
     var_dim0_end = 0; if(var_dim0_end){} 
    __reading = 0;
    __sizeHeader = 0;
    length = 128;
    size = 0;
    var_dim0 = 0;
    vals[var_dim0] = 0;
    var_dim0 = 1;
    vals[var_dim0] = 0;
    var_dim0 = 2;
    vals[var_dim0] = 0;
    var_dim0 = 3;
    vals[var_dim0] = 0;
    __reading = _reading;
    if (__reading)
    {
        while (length&128) {
            __blength = var_bs.getbits(8);
            length=__blength;
            __sizeHeader++;
            size<<=7;
            size|=length&127;
        }
        length=size;
    }
    else
    {
        size=length;
        unsigned int init_length;
        init_length = 0;
        __blength = var_bs.getbits(8);
        __blength = var_bs.getbits(8);
        __blength = var_bs.getbits(8);
        __blength = var_bs.getbits(8);
    }
    
    return var_ret;
}

int descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end;
    var_bs.align(8);
    var_bs.putbits(tag, 8);
     var_dim0_end = 0; if(var_dim0_end){} 
    __v_length = length;
    __reading = 0;
    __sizeHeader = 0;
    length = 128;
    size = 0;
    var_dim0 = 0;
    vals[var_dim0] = 0;
    var_dim0 = 1;
    vals[var_dim0] = 0;
    var_dim0 = 2;
    vals[var_dim0] = 0;
    var_dim0 = 3;
    vals[var_dim0] = 0;
    __reading = _reading;
    if (__reading)
    {
        while (length&128) {
            var_bs.putbits(__blength, 8);
            length=__blength;
            __sizeHeader++;
            size<<=7;
            size|=length&127;
        }
        length=size;
    }
    else
    {
        length = __v_length;
        size=length;
        unsigned int init_length;
        init_length = 0;
        
	init_length = size;
	vals[3] = (unsigned char)  (size & 0x7f);
	size >>= 7;
	vals[2] = (unsigned char) ((size & 0x7f) | 0x80); 
        size >>= 7;
	vals[1] = (unsigned char) ((size & 0x7f) | 0x80); 
	size >>= 7;
	vals[0] = (unsigned char) ((size & 0x7f) | 0x80);
	
        __blength = vals[0];
        var_bs.putbits(__blength, 8);
        __blength = vals[1];
        var_bs.putbits(__blength, 8);
        __blength = vals[2];
        var_bs.putbits(__blength, 8);
        __blength = vals[3];
        var_bs.putbits(__blength, 8);
    }
    
    return var_ret;
}

int language_descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    languageCode = var_bs.getbits(24);
    return var_ret;
}

int language_descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(languageCode, 24);
    return var_ret;
}

int extension_descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    _byte_size = length;
    if (208<=tag&&tag<=223)
    {
        length2 = var_bs.getbits(8);
        _byte_size=length-1;
        
          _ASSERTE(false);
          length = (length << 8) | length2;
      
    }
    
    if (224==tag)
    {
        length2 = var_bs.getbits(24);
        _byte_size=length-3;
        
          _ASSERTE(false);
          length = (length << 24) | length2;
      
    }
    
    
       _row_memory = new BYTE[_byte_size];
   
    __idx = 0;
    for (__idx=0; __idx<_byte_size; __idx++) {
        descriptor_byte = var_bs.getbits(8);
        
         _row_memory[__idx] = descriptor_byte;
      
    }
    return var_ret;
}

int extension_descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    _byte_size = length;
    if (208<=tag&&tag<=223)
    {
        var_bs.putbits(length2, 8);
        _byte_size=length-1;
    }
    
    if (224==tag)
    {
        var_bs.putbits(length2, 24);
        _byte_size=length-3;
    }
    
    __idx = 0;
    for (__idx=0; __idx<_byte_size; __idx++) {
        
          descriptor_byte = _row_memory[__idx];
      
        var_bs.putbits(descriptor_byte, 8);
    }
    return var_ret;
}

int DecoderConfigDescriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    _ASSERTE(TAG_DCD == tag);
    objectProfileIndication = var_bs.getbits(8);
    streamType = var_bs.getbits(6);
    upStream = var_bs.getbits(1);
    reserved = var_bs.getbits(1);
    if (reserved != 1) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    bufferSizeDB = var_bs.getbits(24);
    maxBitrate = var_bs.getbits(32);
    avgBitrate = var_bs.getbits(32);
    if (__reading)
    {
        while (5==var_bs.next(8, 1, 0, 0)) {
            var_bs.align(8);
            p_ext = new(extension_descriptor);
            var_ret += p_ext->get(var_bs);
            _extension_descriptors.push_back(p_ext);
        }
    }
    else
    {
        unsigned int __c;
        __c = 0;
        unsigned int __i;
        __i = 0;
        for (__i=0; __i<__c; __i++) {
            var_bs.align(8);
            p_ext = new(extension_descriptor);
            var_ret += p_ext->get(var_bs);
        }
    }
    
    return var_ret;
}

int DecoderConfigDescriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(objectProfileIndication, 8);
    var_bs.putbits(streamType, 6);
    var_bs.putbits(upStream, 1);
    var_parse = 1;
    reserved = 1;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(bufferSizeDB, 24);
    var_bs.putbits(maxBitrate, 32);
    var_bs.putbits(avgBitrate, 32);
    if (__reading)
    {
        while (5==var_bs.next(8, 1, 0, 0)) {
            var_ret += p_ext->put(var_bs);
        }
    }
    else
    {
        unsigned int __c;
        __c = 0;
        unsigned int __i;
        __i = 0;
        __c = ST_U32(_extension_descriptors.size());
        for (__i=0; __i<__c; __i++) {
              p_ext = _extension_descriptors[__i];
            var_ret += p_ext->put(var_bs);
        }
    }
    
    return var_ret;
}

int SLConfigDescriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    _ASSERTE(TAG_SLC == tag);
    predefined = var_bs.getbits(8);
    if (predefined==0)
    {
        useAccessUnitStartFlag = var_bs.getbits(1);
        useAccessUnitEndFlag = var_bs.getbits(1);
        useRandomAccessPointFlag = var_bs.getbits(1);
        usePaddingFlag = var_bs.getbits(1);
        useTimeStampsFlag = var_bs.getbits(1);
        useWallClockTimeStampFlag = var_bs.getbits(1);
        useIdleFlag = var_bs.getbits(1);
        durationFlag = var_bs.getbits(1);
        timeStampResolution = var_bs.getbits(32);
        OCRResolution = var_bs.getbits(32);
        timeStampLength = var_bs.getbits(8);
        OCRLength = var_bs.getbits(8);
        AU_Length = var_bs.getbits(8);
        instantBitrateLength = var_bs.getbits(8);
        degradationPriorityLength = var_bs.getbits(4);
        seqNumLength = var_bs.getbits(4);
        if (durationFlag)
        {
            timeScale = var_bs.getbits(32);
            accessUnitDuration = var_bs.getbits(16);
            compositionUnitDuration = var_bs.getbits(16);
        }
        
        if (!useTimeStampsFlag)
        {
            if (useWallClockTimeStampFlag)
            {
                wallClockTimeStamp_1 = var_bs.getbits(32);
                wallClockTimeStamp_2 = var_bs.getbits(32);
            }
            
            startDecodingTimeStamp = var_bs.getbits(timeStampLength);
            startCompositionTimeStamp = var_bs.getbits(timeStampLength);
        }
        
        OCRstreamFlag = var_bs.getbits(1);
        reserved = var_bs.getbits(7);
        if (reserved != 127) {
            MG_ERROR(_T("Const value mismatch for 'reserved'"));
            var_ret++;
        }
        if (OCRstreamFlag) {
            OCR_ES_Id = var_bs.getbits(16);
        }
        
    }
    
    return var_ret;
}

int SLConfigDescriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(predefined, 8);
    if (predefined==0)
    {
        var_bs.putbits(useAccessUnitStartFlag, 1);
        var_bs.putbits(useAccessUnitEndFlag, 1);
        var_bs.putbits(useRandomAccessPointFlag, 1);
        var_bs.putbits(usePaddingFlag, 1);
        var_bs.putbits(useTimeStampsFlag, 1);
        var_bs.putbits(useWallClockTimeStampFlag, 1);
        var_bs.putbits(useIdleFlag, 1);
        var_bs.putbits(durationFlag, 1);
        var_bs.putbits(timeStampResolution, 32);
        var_bs.putbits(OCRResolution, 32);
        var_bs.putbits(timeStampLength, 8);
        var_bs.putbits(OCRLength, 8);
        var_bs.putbits(AU_Length, 8);
        var_bs.putbits(instantBitrateLength, 8);
        var_bs.putbits(degradationPriorityLength, 4);
        var_bs.putbits(seqNumLength, 4);
        if (durationFlag)
        {
            var_bs.putbits(timeScale, 32);
            var_bs.putbits(accessUnitDuration, 16);
            var_bs.putbits(compositionUnitDuration, 16);
        }
        
        if (!useTimeStampsFlag)
        {
            if (useWallClockTimeStampFlag)
            {
                var_bs.putbits(wallClockTimeStamp_1, 32);
                var_bs.putbits(wallClockTimeStamp_2, 32);
            }
            
            var_bs.putbits(startDecodingTimeStamp, timeStampLength);
            var_bs.putbits(startCompositionTimeStamp, timeStampLength);
        }
        
        var_bs.putbits(OCRstreamFlag, 1);
        var_parse = 7;
        reserved = 127;
        var_bs.putbits(reserved, var_parse);
        if (OCRstreamFlag) {
            var_bs.putbits(OCR_ES_Id, 16);
        }
        
    }
    
    return var_ret;
}

int IP_IdentificationDataSet::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end, var_dim1, var_dim1_end;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    compatibility = var_bs.getbits(2);
    if (compatibility != 0) {
        MG_ERROR(_T("Const value mismatch for 'compatibility'"));
        var_ret++;
    }
    contentTypeFlag = var_bs.getbits(1);
    contentIdentifierFlag = var_bs.getbits(1);
    var_bs.align(8);
    supplementaryContentIdentifierCount = var_bs.getbits(8);
    if (contentTypeFlag) {
        contentType = var_bs.getbits(8);
    }
    
    if (contentIdentifierFlag)
    {
        contentIdentifierType = var_bs.getbits(8);
        contentIdentifierLength = var_bs.getbits(8);
        var_dim0_end = contentIdentifierLength;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            contentIdentifier[var_dim0] = var_bs.getbits(8);
        }
    }
    
    if (supplementaryContentIdentifierCount>0)
    {
        languageCode = var_bs.getbits(24);
        for (i=0; i<supplementaryContentIdentifierCount; i++) {
            supplementaryContentIdentifierTitleLength = var_bs.getbits(8);
            var_dim0 = i;
            var_dim1_end = supplementaryContentIdentifierTitleLength;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                supplementaryContentIdentifierTitle[var_dim0][var_dim1] = var_bs.getbits(8);
            }
            supplementaryContentIdentifierValueLength = var_bs.getbits(8);
            var_dim0 = i;
            var_dim1_end = supplementaryContentIdentifierValueLength;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                supplementaryContentIdentifierValue[var_dim0][var_dim1] = var_bs.getbits(8);
            }
        }
    }
    
    return var_ret;
}

int IP_IdentificationDataSet::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim0_end, var_dim1, var_dim1_end;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_parse = 2;
    compatibility = 0;
    var_bs.putbits(compatibility, var_parse);
    var_bs.putbits(contentTypeFlag, 1);
    var_bs.putbits(contentIdentifierFlag, 1);
    var_bs.align(8);
    var_bs.putbits(supplementaryContentIdentifierCount, 8);
    if (contentTypeFlag) {
        var_bs.putbits(contentType, 8);
    }
    
    if (contentIdentifierFlag)
    {
        var_bs.putbits(contentIdentifierType, 8);
        var_bs.putbits(contentIdentifierLength, 8);
        var_dim0_end = contentIdentifierLength;
        for (var_dim0 = 0; var_dim0 < var_dim0_end; var_dim0++) {
            var_bs.putbits(contentIdentifier[var_dim0], 8);
        }
    }
    
    if (supplementaryContentIdentifierCount>0)
    {
        var_bs.putbits(languageCode, 24);
        for (i=0; i<supplementaryContentIdentifierCount; i++) {
            var_bs.putbits(supplementaryContentIdentifierTitleLength, 8);
            var_dim0 = i;
            var_dim1_end = supplementaryContentIdentifierTitleLength;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                var_bs.putbits(supplementaryContentIdentifierTitle[var_dim0][var_dim1], 8);
            }
            var_bs.putbits(supplementaryContentIdentifierValueLength, 8);
            var_dim0 = i;
            var_dim1_end = supplementaryContentIdentifierValueLength;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                var_bs.putbits(supplementaryContentIdentifierValue[var_dim0][var_dim1], 8);
            }
        }
    }
    
    return var_ret;
}

int IPI_DescPointer::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    IPI_ES_Id = var_bs.getbits(16);
    return var_ret;
}

int IPI_DescPointer::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(IPI_ES_Id, 16);
    return var_ret;
}

int QoS_Descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim1, var_dim1_end;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    predefined = var_bs.getbits(8);
    if (predefined==0)
    {
        QoS_QualifierCount = var_bs.getbits(8);
        for (i=0; i<QoS_QualifierCount; i++) {
            var_dim0 = i;
            QoS_QualifierTag[var_dim0] = var_bs.getbits(8);
            var_dim0 = i;
            QoS_QualifierLength[var_dim0] = var_bs.getbits(8);
            x=QoS_QualifierLength[i];
            var_dim0 = i;
            var_dim1_end = x;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                QoS_QualifierData[var_dim0][var_dim1] = var_bs.getbits(8);
            }
        }
    }
    
    return var_ret;
}

int QoS_Descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0, var_dim1, var_dim1_end;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(predefined, 8);
    if (predefined==0)
    {
        var_bs.putbits(QoS_QualifierCount, 8);
        for (i=0; i<QoS_QualifierCount; i++) {
            var_dim0 = i;
            var_bs.putbits(QoS_QualifierTag[var_dim0], 8);
            var_dim0 = i;
            var_bs.putbits(QoS_QualifierLength[var_dim0], 8);
            x=QoS_QualifierLength[i];
            var_dim0 = i;
            var_dim1_end = x;
            for (var_dim1 = 0; var_dim1 < var_dim1_end; var_dim1++) {
                var_bs.putbits(QoS_QualifierData[var_dim0][var_dim1], 8);
            }
        }
    }
    
    return var_ret;
}

int ES_Descriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    _ASSERTE(TAG_ESD == tag);
    ES_ID = var_bs.getbits(16);
    streamDependenceFlag = var_bs.getbits(1);
    URL_Flag = var_bs.getbits(1);
    OCR_Flag = var_bs.getbits(1);
    streamPriority = var_bs.getbits(5);
    if (streamDependenceFlag) {
        dependsOn_ES_ID = var_bs.getbits(16);
    }
    
    if (URL_Flag)
    {
        s_size = var_bs.getbits(8);
        unsigned int __idx;
        __idx = 0;
        for (__idx=0; __idx<s_size; __idx++) {
            var_dim0 = __idx;
            URLstring[var_dim0] = var_bs.getbits(8);
        }
    }
    
    if (OCR_Flag)
    {
        OCRESID = var_bs.getbits(16);
    }
    
    if (__reading)
    {
        while ((128<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=175)||(208<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=223)) {
            var_bs.align(8);
            p_ext = new(extension_descriptor);
            var_ret += p_ext->get(var_bs);
            _extension_descriptors.push_back(p_ext);
            if(dynamic_cast<IBitstream3 & >(var_bs).eof())
			     break;
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (67==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_lang = new(language_descriptor);
                var_ret += p_lang->get(var_bs);
            }
            
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (4==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_decoder_config_descriptor = new(DecoderConfigDescriptor);
                var_ret += p_decoder_config_descriptor->get(var_bs);
            }
            
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (6==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_sl_config_descriptor = new(SLConfigDescriptor);
                var_ret += p_sl_config_descriptor->get(var_bs);
            }
            
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (18==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_ipi_desc_pointer = new(IPI_DescPointer);
                var_ret += p_ipi_desc_pointer->get(var_bs);
            }
            
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (38==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_ip_idset = new(IP_IdentificationDataSet);
                var_ret += p_ip_idset->get(var_bs);
            }
            
        }
        if(!dynamic_cast<IBitstream3 & >(var_bs).eof())
        {
            if (12==var_bs.next(8, 1, 0, 0))
            {
                var_bs.align(8);
                p_qos = new(QoS_Descriptor);
                var_ret += p_qos->get(var_bs);
            }
            
        }
        _ASSERTE(NULL != p_decoder_config_descriptor);
	   _ASSERTE(NULL != p_sl_config_descriptor);
    }
    else
    {
        var_bs.align(8);
        p_decoder_config_descriptor = new(DecoderConfigDescriptor);
        var_ret += p_decoder_config_descriptor->get(var_bs);
        var_bs.align(8);
        p_sl_config_descriptor = new(SLConfigDescriptor);
        var_ret += p_sl_config_descriptor->get(var_bs);
    }
    
    return var_ret;
}

int ES_Descriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(ES_ID, 16);
    var_bs.putbits(streamDependenceFlag, 1);
    var_bs.putbits(URL_Flag, 1);
    var_bs.putbits(OCR_Flag, 1);
    var_bs.putbits(streamPriority, 5);
    if (streamDependenceFlag) {
        var_bs.putbits(dependsOn_ES_ID, 16);
    }
    
    if (URL_Flag)
    {
        var_bs.putbits(s_size, 8);
        unsigned int __idx;
        __idx = 0;
        for (__idx=0; __idx<s_size; __idx++) {
            var_dim0 = __idx;
            var_bs.putbits(URLstring[var_dim0], 8);
        }
    }
    
    if (OCR_Flag)
    {
        var_bs.putbits(OCRESID, 16);
    }
    
    if (__reading)
    {
        while ((128<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=175)||(208<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=223)) {
            var_ret += p_ext->put(var_bs);
        }
        {
            if (67==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_lang->put(var_bs);
            }
            
        }
        {
            if (4==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_decoder_config_descriptor->put(var_bs);
            }
            
        }
        {
            if (6==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_sl_config_descriptor->put(var_bs);
            }
            
        }
        {
            if (18==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_ipi_desc_pointer->put(var_bs);
            }
            
        }
        {
            if (38==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_ip_idset->put(var_bs);
            }
            
        }
        {
            if (12==var_bs.next(8, 1, 0, 0))
            {
                var_ret += p_qos->put(var_bs);
            }
            
        }
    }
    else
    {
        var_ret += p_decoder_config_descriptor->put(var_bs);
        var_ret += p_sl_config_descriptor->put(var_bs);
    }
    
    return var_ret;
}

int OCIGenericDescriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += extension_descriptor::get(var_bs);
    return var_ret;
}

int OCIGenericDescriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += extension_descriptor::put(var_bs);
    return var_ret;
}

int InitialObjectDescriptor::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += descriptor::get(var_bs);
    ObjectDescriptorID = var_bs.getbits(10);
    URL_Flag = var_bs.getbits(1);
    includeInlineProfilesFlag = var_bs.getbits(1);
    reserved = var_bs.getbits(4);
    if (URL_Flag)
    {
        s_size = var_bs.getbits(8);
        unsigned int __idx;
        __idx = 0;
        for (__idx=0; __idx<s_size; __idx++) {
            var_dim0 = __idx;
            URLstring[var_dim0] = var_bs.getbits(8);
        }
    }
    else
    {
        OD = var_bs.getbits(8);
        sceneProfile = var_bs.getbits(8);
        audioProfile = var_bs.getbits(8);
        visualProfile = var_bs.getbits(8);
        graphicsProfile = var_bs.getbits(8);
    }
    
    if (__reading)
    {
        while ((128<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=175)||(208<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=223)) {
            var_bs.align(8);
            p_ext = new(extension_descriptor);
            var_ret += p_ext->get(var_bs);
            _extension_descriptors.push_back(p_ext);
        }
    }
    
    if (!URL_Flag)
    {
        if (__reading)
        {
            while (64<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<80) {
                var_bs.align(8);
                p_oci = new(OCIGenericDescriptor);
                var_ret += p_oci->get(var_bs);
                _oci_descriptors.push_back(p_oci);
            }
            while (3==var_bs.next(8, 1, 0, 0)) {
                var_bs.align(8);
                p_esd = new(ES_Descriptor);
                var_ret += p_esd->get(var_bs);
                 _es_descriptors.push_back(p_esd);
            }
        }
        
    }
    
    return var_ret;
}

int InitialObjectDescriptor::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += descriptor::put(var_bs);
    var_bs.putbits(ObjectDescriptorID, 10);
    var_bs.putbits(URL_Flag, 1);
    var_bs.putbits(includeInlineProfilesFlag, 1);
    var_bs.putbits(reserved, 4);
    if (URL_Flag)
    {
        var_bs.putbits(s_size, 8);
        unsigned int __idx;
        __idx = 0;
        for (__idx=0; __idx<s_size; __idx++) {
            var_dim0 = __idx;
            var_bs.putbits(URLstring[var_dim0], 8);
        }
    }
    else
    {
        var_bs.putbits(OD, 8);
        var_bs.putbits(sceneProfile, 8);
        var_bs.putbits(audioProfile, 8);
        var_bs.putbits(visualProfile, 8);
        var_bs.putbits(graphicsProfile, 8);
    }
    
    if (__reading)
    {
        while ((128<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=175)||(208<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<=223)) {
            var_ret += p_ext->put(var_bs);
        }
    }
    
    if (!URL_Flag)
    {
        if (__reading)
        {
            while (64<=var_bs.next(8, 1, 0, 0)&&var_bs.next(8, 1, 0, 0)<80) {
                var_ret += p_oci->put(var_bs);
            }
            while (3==var_bs.next(8, 1, 0, 0)) {
                var_ret += p_esd->put(var_bs);
            }
        }
        
    }
    
    return var_ret;
}

__ALX_END_NAMESPACE
