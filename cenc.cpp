/* @mediagen - Change defaults on Dockerfile -
 *
 * cenc.cpp
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

#include "stdafx.h"
#include <TBitstream.h>
#include "cenc.h"


__ALX_BEGIN_NAMESPACE

int AssetInformationBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    profile_version = var_bs.sgetbits(32);
    return var_ret;
}

int AssetInformationBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(profile_version, 32);
    return var_ret;
}

int OriginalFormatBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    data_format = var_bs.getbits(32);
    
         I2C(data_format, _stype);
   
    return var_ret;
}

int OriginalFormatBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(data_format, 32);
    return var_ret;
}

int SchemeTypeBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    scheme_type = var_bs.getbits(32);
    scheme_version = var_bs.getbits(32);
    if (flags&1)
    {
        scheme_uri = var_bs.getbits(8);
    }
    
    
         I2C(scheme_type, _stype);
   
    return var_ret;
}

int SchemeTypeBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(scheme_type, 32);
    var_bs.putbits(scheme_version, 32);
    if (flags&1)
    {
        var_bs.putbits(scheme_uri, 8);
    }
    
    return var_ret;
}

int TrackEncryptionBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    if (version==0)
    {
        reserved2 = var_bs.getbits(8);
        if (reserved2 != 0) {
            MG_ERROR(_T("Const value mismatch for 'reserved2'"));
            var_ret++;
        }
    }
    else
    {
        default_crypt_byte_block = var_bs.getbits(4);
        default_skip_byte_block = var_bs.getbits(4);
    }
    
    default_isProtected = var_bs.getbits(8);
    default_Per_Sample_IV_Size = var_bs.getbits(8);
    default_KID = var_bs.getbits(8);
    default_KID_0 = var_bs.getbits(8);
    default_KID_1 = var_bs.getbits(8);
    default_KID_2 = var_bs.getbits(8);
    default_KID_3 = var_bs.getbits(8);
    default_KID_4 = var_bs.getbits(8);
    default_KID_5 = var_bs.getbits(8);
    default_KID_6 = var_bs.getbits(8);
    default_KID_7 = var_bs.getbits(8);
    default_KID_8 = var_bs.getbits(8);
    default_KID_9 = var_bs.getbits(8);
    default_KID_10 = var_bs.getbits(8);
    default_KID_11 = var_bs.getbits(8);
    default_KID_12 = var_bs.getbits(8);
    default_KID_13 = var_bs.getbits(8);
    default_KID_14 = var_bs.getbits(8);
    if (default_isProtected==1&&default_Per_Sample_IV_Size==0)
    {
        default_constant_IV_size = var_bs.getbits(8);
        unsigned int x;
        x = 0;
        for (x=0; x<default_constant_IV_size; x++) {
            var_dim0 = x;
            default_constant_IV[var_dim0] = var_bs.getbits(8);
        }
    }
    
    return var_ret;
}

int TrackEncryptionBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_dim0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    if (version==0)
    {
        var_parse = 8;
        reserved2 = 0;
        var_bs.putbits(reserved2, var_parse);
    }
    else
    {
        var_bs.putbits(default_crypt_byte_block, 4);
        var_bs.putbits(default_skip_byte_block, 4);
    }
    
    var_bs.putbits(default_isProtected, 8);
    var_bs.putbits(default_Per_Sample_IV_Size, 8);
    var_bs.putbits(default_KID, 8);
    var_bs.putbits(default_KID_0, 8);
    var_bs.putbits(default_KID_1, 8);
    var_bs.putbits(default_KID_2, 8);
    var_bs.putbits(default_KID_3, 8);
    var_bs.putbits(default_KID_4, 8);
    var_bs.putbits(default_KID_5, 8);
    var_bs.putbits(default_KID_6, 8);
    var_bs.putbits(default_KID_7, 8);
    var_bs.putbits(default_KID_8, 8);
    var_bs.putbits(default_KID_9, 8);
    var_bs.putbits(default_KID_10, 8);
    var_bs.putbits(default_KID_11, 8);
    var_bs.putbits(default_KID_12, 8);
    var_bs.putbits(default_KID_13, 8);
    var_bs.putbits(default_KID_14, 8);
    if (default_isProtected==1&&default_Per_Sample_IV_Size==0)
    {
        var_bs.putbits(default_constant_IV_size, 8);
        unsigned int x;
        x = 0;
        for (x=0; x<default_constant_IV_size; x++) {
            var_dim0 = x;
            var_bs.putbits(default_constant_IV[var_dim0], 8);
        }
    }
    
    return var_ret;
}

int SampleEncryptionInitializationVector64::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    InitializationVector_0 = var_bs.getbits(8);
    InitializationVector_1 = var_bs.getbits(8);
    InitializationVector_2 = var_bs.getbits(8);
    InitializationVector_3 = var_bs.getbits(8);
    InitializationVector_4 = var_bs.getbits(8);
    InitializationVector_5 = var_bs.getbits(8);
    InitializationVector_6 = var_bs.getbits(8);
    InitializationVector_7 = var_bs.getbits(8);
    return var_ret;
}

int SampleEncryptionInitializationVector64::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(InitializationVector_0, 8);
    var_bs.putbits(InitializationVector_1, 8);
    var_bs.putbits(InitializationVector_2, 8);
    var_bs.putbits(InitializationVector_3, 8);
    var_bs.putbits(InitializationVector_4, 8);
    var_bs.putbits(InitializationVector_5, 8);
    var_bs.putbits(InitializationVector_6, 8);
    var_bs.putbits(InitializationVector_7, 8);
    return var_ret;
}

int SubSampleEncryptionBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    BytesOfClearData = var_bs.getbits(16);
    BytesOfProtectedData = var_bs.getbits(32);
    return var_ret;
}

int SubSampleEncryptionBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(BytesOfClearData, 16);
    var_bs.putbits(BytesOfProtectedData, 32);
    return var_ret;
}

int SingleEncryptionBox::get(IBitstream &var_bs, int ff) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.align(8);
    init_vector = new(SampleEncryptionInitializationVector64);
    var_ret += init_vector->get(var_bs);
    if (ff&2)
    {
        subsample_count = var_bs.getbits(16);
        unsigned int i;
        i = 0;
        for (i=0; i<subsample_count; i++) {
            var_bs.align(8);
            _p_sub_sample = new(SubSampleEncryptionBox);
            var_ret += _p_sub_sample->get(var_bs);
            _sub_samples.push_back(_p_sub_sample);
        }
    }
    
    return var_ret;
}

int SingleEncryptionBox::put(IBitstream &var_bs, int ff) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += init_vector->put(var_bs);
    if (ff&2)
    {
        var_bs.putbits(subsample_count, 16);
        unsigned int i;
        i = 0;
        for (i=0; i<subsample_count; i++) {
             _p_sub_sample = _sub_samples[i]; 
            var_ret += _p_sub_sample->put(var_bs);
        }
    }
    
    return var_ret;
}

int SampleEncryptionBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    sample_count = var_bs.getbits(32);
    i = 0;
    for (i=0; i<sample_count; i++) {
        var_bs.align(8);
        _p_single_box = new(SingleEncryptionBox);
        var_ret += _p_single_box->get(var_bs, flags);
        _samples.push_back(_p_single_box);
    }
    return var_ret;
}

int SampleEncryptionBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(sample_count, 32);
    i = 0;
    for (i=0; i<sample_count; i++) {
         _p_single_box = _samples[i]; 
        var_ret += _p_single_box->put(var_bs, flags);
    }
    return var_ret;
}

int SampleAuxiliaryInformationSizesBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (flags&1)
    {
        aux_info_type = var_bs.getbits(32);
        aux_info_type_parameter = var_bs.getbits(32);
    }
    
    default_sample_info_size = var_bs.getbits(8);
    sample_count = var_bs.getbits(32);
    if (default_sample_info_size==0)
    {
        unsigned int i;
        i = 0;
        for (i=0; i<sample_count; i++) {
            sample_info_size = var_bs.getbits(8);
            _samples_info_size.push_back(sample_info_size);
        }
    }
    
    return var_ret;
}

int SampleAuxiliaryInformationSizesBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (flags&1)
    {
        var_bs.putbits(aux_info_type, 32);
        var_bs.putbits(aux_info_type_parameter, 32);
    }
    
    var_bs.putbits(default_sample_info_size, 8);
    var_bs.putbits(sample_count, 32);
    if (default_sample_info_size==0)
    {
        unsigned int i;
        i = 0;
        for (i=0; i<sample_count; i++) {
             sample_info_size = _samples_info_size[i]; 
            var_bs.putbits(sample_info_size, 8);
        }
    }
    
    return var_ret;
}

int SampleAuxiliaryInformationOffsetsBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (flags&1)
    {
        aux_info_type = var_bs.getbits(32);
        aux_info_type_parameter = var_bs.getbits(32);
    }
    
    entry_count = var_bs.getbits(32);
    i = 0;
    for (i=0; i<entry_count; i++) {
        offset = var_bs.getbits(32);
        if (version==0)
        {
        }
        else
        {
            offset_0 = var_bs.getbits(32);
        }
        
        _samples_offset.push_back(get_offset());
    }
    return var_ret;
}

int SampleAuxiliaryInformationOffsetsBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (flags&1)
    {
        var_bs.putbits(aux_info_type, 32);
        var_bs.putbits(aux_info_type_parameter, 32);
    }
    
    var_bs.putbits(entry_count, 32);
    i = 0;
    for (i=0; i<entry_count; i++) {
         set_offset(_samples_offset[i]); 
        var_bs.putbits(offset, 32);
        if (version==0)
        {
        }
        else
        {
            var_bs.putbits(offset_0, 32);
        }
        
    }
    return var_ret;
}

int ProtectionSystemSpecificHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    SystemID = var_bs.getbits(8);
    SystemID_1 = var_bs.getbits(8);
    SystemID_2 = var_bs.getbits(8);
    SystemID_3 = var_bs.getbits(8);
    SystemID_4 = var_bs.getbits(8);
    SystemID_5 = var_bs.getbits(8);
    SystemID_6 = var_bs.getbits(8);
    SystemID_7 = var_bs.getbits(8);
    SystemID_8 = var_bs.getbits(8);
    SystemID_9 = var_bs.getbits(8);
    SystemID_10 = var_bs.getbits(8);
    SystemID_11 = var_bs.getbits(8);
    SystemID_12 = var_bs.getbits(8);
    SystemID_13 = var_bs.getbits(8);
    SystemID_14 = var_bs.getbits(8);
    SystemID_15 = var_bs.getbits(8);
    _end = 0;
    if (version>0)
    {
        KID_count = var_bs.getbits(32);
        unsigned int i;
        i = 0;
        for (i=0; i<KID_count; i++) {
            KID = var_bs.getbits(8);
            KID_1 = var_bs.getbits(8);
            KID_2 = var_bs.getbits(8);
            KID_3 = var_bs.getbits(8);
            KID_4 = var_bs.getbits(8);
            KID_5 = var_bs.getbits(8);
            KID_6 = var_bs.getbits(8);
            KID_7 = var_bs.getbits(8);
            KID_8 = var_bs.getbits(8);
            KID_9 = var_bs.getbits(8);
            KID_10 = var_bs.getbits(8);
            KID_11 = var_bs.getbits(8);
            KID_12 = var_bs.getbits(8);
            KID_13 = var_bs.getbits(8);
            KID_14 = var_bs.getbits(8);
            KID_15 = var_bs.getbits(8);
        }
    }
    
    DataSize = var_bs.getbits(32);
      _p_data = new unsigned char[DataSize]; 
    k = 0;
    for (k=0; k<DataSize; k++) {
        Data = var_bs.getbits(8);
          _p_data[k] = Data; 
    }
    return var_ret;
}

int ProtectionSystemSpecificHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(SystemID, 8);
    var_bs.putbits(SystemID_1, 8);
    var_bs.putbits(SystemID_2, 8);
    var_bs.putbits(SystemID_3, 8);
    var_bs.putbits(SystemID_4, 8);
    var_bs.putbits(SystemID_5, 8);
    var_bs.putbits(SystemID_6, 8);
    var_bs.putbits(SystemID_7, 8);
    var_bs.putbits(SystemID_8, 8);
    var_bs.putbits(SystemID_9, 8);
    var_bs.putbits(SystemID_10, 8);
    var_bs.putbits(SystemID_11, 8);
    var_bs.putbits(SystemID_12, 8);
    var_bs.putbits(SystemID_13, 8);
    var_bs.putbits(SystemID_14, 8);
    var_bs.putbits(SystemID_15, 8);
    _end = 0;
    if (version>0)
    {
        var_bs.putbits(KID_count, 32);
        unsigned int i;
        i = 0;
        for (i=0; i<KID_count; i++) {
            var_bs.putbits(KID, 8);
            var_bs.putbits(KID_1, 8);
            var_bs.putbits(KID_2, 8);
            var_bs.putbits(KID_3, 8);
            var_bs.putbits(KID_4, 8);
            var_bs.putbits(KID_5, 8);
            var_bs.putbits(KID_6, 8);
            var_bs.putbits(KID_7, 8);
            var_bs.putbits(KID_8, 8);
            var_bs.putbits(KID_9, 8);
            var_bs.putbits(KID_10, 8);
            var_bs.putbits(KID_11, 8);
            var_bs.putbits(KID_12, 8);
            var_bs.putbits(KID_13, 8);
            var_bs.putbits(KID_14, 8);
            var_bs.putbits(KID_15, 8);
        }
    }
    
    var_bs.putbits(DataSize, 32);
    k = 0;
    for (k=0; k<DataSize; k++) {
          Data = _p_data[k]; 
        var_bs.putbits(Data, 8);
    }
    return var_ret;
}

int SampleToGroupBoxItem::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    sample_count = var_bs.getbits(32);
    group_description_index = var_bs.getbits(32);
    return var_ret;
}

int SampleToGroupBoxItem::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(sample_count, 32);
    var_bs.putbits(group_description_index, 32);
    return var_ret;
}

int SampleToGroupBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    grouping_type = var_bs.getbits(32);
    if (version==1)
    {
        grouping_type_parameter = var_bs.getbits(32);
    }
    
    entry_count = var_bs.getbits(32);
    i = 0;
    for (i=1; i<=entry_count; i++) {
        var_bs.align(8);
        _item = new(SampleToGroupBoxItem);
        var_ret += _item->get(var_bs);
        _samples.push_back(_item);
    }
    return var_ret;
}

int SampleToGroupBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(grouping_type, 32);
    if (version==1)
    {
        var_bs.putbits(grouping_type_parameter, 32);
    }
    
    var_bs.putbits(entry_count, 32);
    i = 0;
    for (i=1; i<=entry_count; i++) {
         _item = _samples[i]; 
        var_ret += _item->put(var_bs);
    }
    return var_ret;
}

int CencSampleEncryptionInformationGroupEntry::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    reserved = var_bs.getbits(8);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    crypt_byte_block = var_bs.getbits(4);
    if (crypt_byte_block != 0) {
        MG_ERROR(_T("Const value mismatch for 'crypt_byte_block'"));
        var_ret++;
    }
    skip_byte_block = var_bs.getbits(4);
    if (skip_byte_block != 0) {
        MG_ERROR(_T("Const value mismatch for 'skip_byte_block'"));
        var_ret++;
    }
    isProtected = var_bs.getbits(8);
    Per_Sample_IV_Size = var_bs.getbits(8);
    KID = var_bs.getbits(8);
    KID_1 = var_bs.getbits(8);
    KID_2 = var_bs.getbits(8);
    KID_3 = var_bs.getbits(8);
    KID_4 = var_bs.getbits(8);
    KID_5 = var_bs.getbits(8);
    KID_6 = var_bs.getbits(8);
    KID_7 = var_bs.getbits(8);
    KID_8 = var_bs.getbits(8);
    KID_9 = var_bs.getbits(8);
    KID_10 = var_bs.getbits(8);
    KID_11 = var_bs.getbits(8);
    KID_12 = var_bs.getbits(8);
    KID_13 = var_bs.getbits(8);
    KID_14 = var_bs.getbits(8);
    KID_15 = var_bs.getbits(8);
    if (isProtected==1&&Per_Sample_IV_Size==0)
    {
        constant_IV_size = var_bs.getbits(8);
        unsigned int k;
        k = 0;
        for (k=0; k<constant_IV_size; k++) {
            constant_IV = var_bs.getbits(8);
        }
    }
    
    return var_ret;
}

int CencSampleEncryptionInformationGroupEntry::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_parse = 8;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_parse = 4;
    crypt_byte_block = 0;
    var_bs.putbits(crypt_byte_block, var_parse);
    var_parse = 4;
    skip_byte_block = 0;
    var_bs.putbits(skip_byte_block, var_parse);
    var_bs.putbits(isProtected, 8);
    var_bs.putbits(Per_Sample_IV_Size, 8);
    var_bs.putbits(KID, 8);
    var_bs.putbits(KID_1, 8);
    var_bs.putbits(KID_2, 8);
    var_bs.putbits(KID_3, 8);
    var_bs.putbits(KID_4, 8);
    var_bs.putbits(KID_5, 8);
    var_bs.putbits(KID_6, 8);
    var_bs.putbits(KID_7, 8);
    var_bs.putbits(KID_8, 8);
    var_bs.putbits(KID_9, 8);
    var_bs.putbits(KID_10, 8);
    var_bs.putbits(KID_11, 8);
    var_bs.putbits(KID_12, 8);
    var_bs.putbits(KID_13, 8);
    var_bs.putbits(KID_14, 8);
    var_bs.putbits(KID_15, 8);
    if (isProtected==1&&Per_Sample_IV_Size==0)
    {
        var_bs.putbits(constant_IV_size, 8);
        unsigned int k;
        k = 0;
        for (k=0; k<constant_IV_size; k++) {
            var_bs.putbits(constant_IV, 8);
        }
    }
    
    return var_ret;
}

int SampleGroupDescriptionBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    grouping_type = var_bs.getbits(32);
    if (version==1)
    {
        default_length = var_bs.getbits(32);
    }
    
    entry_count = var_bs.getbits(32);
    i = 0;
    for (i=1; i<=entry_count; i++) {
        if (version==1)
        {
            if (default_length==0)
            {
                description_length = var_bs.getbits(32);
            }
            
        }
        
        if (1936025959==grouping_type)
        {
            var_bs.align(8);
            _seig = new(CencSampleEncryptionInformationGroupEntry);
            var_ret += _seig->get(var_bs);
        }
        
    }
    return var_ret;
}

int SampleGroupDescriptionBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(grouping_type, 32);
    if (version==1)
    {
        var_bs.putbits(default_length, 32);
    }
    
    var_bs.putbits(entry_count, 32);
    i = 0;
    for (i=1; i<=entry_count; i++) {
        if (version==1)
        {
            if (default_length==0)
            {
                var_bs.putbits(description_length, 32);
            }
            
        }
        
        if (1936025959==grouping_type)
        {
            var_ret += _seig->put(var_bs);
        }
        
    }
    return var_ret;
}

__ALX_END_NAMESPACE
