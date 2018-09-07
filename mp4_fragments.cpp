/* @mediagen - fix appveyor api url missing slash -
 *
 * mp4_fragments.cpp
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

#include "stdafx.h"
#include <TBitstream.h>
#include "mp4_fragments.h"


__ALX_BEGIN_NAMESPACE

int MovieExtendsHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (version==1)
    {
        fragment_duration_0 = var_bs.getbits(32);
        fragment_duration = var_bs.getbits(32);
    }
    else
    {
        fragment_duration = var_bs.getbits(32);
    }
    
    return var_ret;
}

int MovieExtendsHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (version==1)
    {
        var_bs.putbits(fragment_duration_0, 32);
        var_bs.putbits(fragment_duration, 32);
    }
    else
    {
        var_bs.putbits(fragment_duration, 32);
    }
    
    return var_ret;
}

int TrackExtendsBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    track_ID = var_bs.getbits(32);
    default_sample_description_index = var_bs.getbits(32);
    default_sample_duration = var_bs.getbits(32);
    default_sample_size = var_bs.getbits(32);
    default_sample_flags = var_bs.getbits(32);
    return var_ret;
}

int TrackExtendsBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(track_ID, 32);
    var_bs.putbits(default_sample_description_index, 32);
    var_bs.putbits(default_sample_duration, 32);
    var_bs.putbits(default_sample_size, 32);
    var_bs.putbits(default_sample_flags, 32);
    return var_ret;
}

int MovieFragmentHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    sequence_number = var_bs.getbits(32);
    return var_ret;
}

int MovieFragmentHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(sequence_number, 32);
    return var_ret;
}

int TrackFragmentHeaderBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    track_ID = var_bs.getbits(32);
    if (1&flags)
    {
        base_data_offset_0 = var_bs.getbits(32);
        base_data_offset = var_bs.getbits(32);
    }
    
    if (2&flags) {
        sample_description_index = var_bs.getbits(32);
        if (sample_description_index != 1) {
            MG_ERROR(_T("Const value mismatch for 'sample_description_index'"));
            var_ret++;
        }
    }
    
    if (8&flags) {
        default_sample_duration = var_bs.getbits(32);
    }
    
    if (16&flags) {
        default_sample_size = var_bs.getbits(32);
    }
    
    if (32&flags) {
        default_sample_flags = var_bs.getbits(32);
    }
    
    return var_ret;
}

int TrackFragmentHeaderBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(track_ID, 32);
    if (1&flags)
    {
        var_bs.putbits(base_data_offset_0, 32);
        var_bs.putbits(base_data_offset, 32);
    }
    
    if (2&flags) {
        var_parse = 32;
        sample_description_index = 1;
        var_bs.putbits(sample_description_index, var_parse);
    }
    
    if (8&flags) {
        var_bs.putbits(default_sample_duration, 32);
    }
    
    if (16&flags) {
        var_bs.putbits(default_sample_size, 32);
    }
    
    if (32&flags) {
        var_bs.putbits(default_sample_flags, 32);
    }
    
    return var_ret;
}

int trun_body::get(IBitstream &var_bs, unsigned int flags) {
    int var_ret = 0;
    var_bs.align(8);
    if (256&flags) {
        sample_duration = var_bs.getbits(32);
    }
    
    if (512&flags) {
        sample_size = var_bs.getbits(32);
    }
    
    if (1024&flags) {
        sample_flags = var_bs.getbits(32);
    }
    
    if (2048&flags) {
        sample_composition_time_offset = var_bs.getbits(32);
    }
    
    return var_ret;
}

int trun_body::put(IBitstream &var_bs, unsigned int flags) {
    int var_ret = 0;
    var_bs.align(8);
    if (256&flags) {
        var_bs.putbits(sample_duration, 32);
    }
    
    if (512&flags) {
        var_bs.putbits(sample_size, 32);
    }
    
    if (1024&flags) {
        var_bs.putbits(sample_flags, 32);
    }
    
    if (2048&flags) {
        var_bs.putbits(sample_composition_time_offset, 32);
    }
    
    return var_ret;
}

int TrackRunBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    sample_count = var_bs.getbits(32);
    if (1&flags) {
        data_offset = var_bs.sgetbits(32);
    }
    
    if (4&flags) {
        first_sample_flags = var_bs.getbits(32);
    }
    
    __i = 0;
    for (__i=0; __i<sample_count; __i++) {
        var_bs.align(8);
        _p_trun_body = new(trun_body);
        var_ret += _p_trun_body->get(var_bs, flags);
        
		    _samples.push_back(_p_trun_body);
	  
    }
    return var_ret;
}

int TrackRunBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    
		    sample_count = ST_U32(_samples.size());
	  
    var_bs.putbits(sample_count, 32);
    if (1&flags) {
        var_bs.putbits(data_offset, 32);
    }
    
    if (4&flags) {
        var_bs.putbits(first_sample_flags, 32);
    }
    
    __i = 0;
    for (__i=0; __i<sample_count; __i++) {
        
		    _ASSERTE(__i < _samples.size());
		    _p_trun_body = _samples[__i];
	  
        var_ret += _p_trun_body->put(var_bs, flags);
    }
    return var_ret;
}

int TrackFragmentRandomAccessBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    track_ID = var_bs.getbits(32);
    reserved = var_bs.getbits(26);
    if (reserved != 0) {
        MG_ERROR(_T("Const value mismatch for 'reserved'"));
        var_ret++;
    }
    length_size_of_traf_num = var_bs.getbits(2);
    length_size_of_trun_num = var_bs.getbits(2);
    length_size_of_sample_num = var_bs.getbits(2);
    number_of_entry = var_bs.getbits(32);
    for (i=1; i<=number_of_entry; i++) {
        if (version==1)
        {
            time_0 = var_bs.getbits(32);
            time = var_bs.getbits(32);
            moof_offset_0 = var_bs.getbits(32);
            moof_offset = var_bs.getbits(32);
        }
        else
        {
            time = var_bs.getbits(32);
            moof_offset = var_bs.getbits(32);
        }
        
        traf_number = var_bs.getbits((length_size_of_traf_num+1)*8);
        trun_number = var_bs.getbits((length_size_of_trun_num+1)*8);
        sample_number = var_bs.getbits((length_size_of_sample_num+1)*8);
        
		 index_item(
			  get_time()
			, get_moof_offset()
			, traf_number
			, trun_number
			, sample_number
			);
     
    }
    return var_ret;
}

int TrackFragmentRandomAccessBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    int var_parse = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    var_bs.putbits(track_ID, 32);
    var_parse = 26;
    reserved = 0;
    var_bs.putbits(reserved, var_parse);
    var_bs.putbits(length_size_of_traf_num, 2);
    var_bs.putbits(length_size_of_trun_num, 2);
    var_bs.putbits(length_size_of_sample_num, 2);
    var_bs.putbits(number_of_entry, 32);
    for (i=1; i<=number_of_entry; i++) {
        if (version==1)
        {
            var_bs.putbits(time_0, 32);
            var_bs.putbits(time, 32);
            var_bs.putbits(moof_offset_0, 32);
            var_bs.putbits(moof_offset, 32);
        }
        else
        {
            var_bs.putbits(time, 32);
            var_bs.putbits(moof_offset, 32);
        }
        
        var_bs.putbits(traf_number, (length_size_of_traf_num+1)*8);
        var_bs.putbits(trun_number, (length_size_of_trun_num+1)*8);
        var_bs.putbits(sample_number, (length_size_of_sample_num+1)*8);
    }
    return var_ret;
}

int TrackFragmentBaseMediaDecodeTimeBox::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::get(var_bs);
    if (version==1)
    {
        baseMediaDecodeTime_0 = var_bs.getbits(32);
        baseMediaDecodeTime = var_bs.getbits(32);
    }
    else
    {
        baseMediaDecodeTime = var_bs.getbits(32);
    }
    
    return var_ret;
}

int TrackFragmentBaseMediaDecodeTimeBox::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_ret += FullBox::put(var_bs);
    if (version==1)
    {
        var_bs.putbits(baseMediaDecodeTime_0, 32);
        var_bs.putbits(baseMediaDecodeTime, 32);
    }
    else
    {
        var_bs.putbits(baseMediaDecodeTime, 32);
    }
    
    return var_ret;
}

int TrickPlayBoxRecord::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    pic_type = var_bs.getbits(2);
    dependency_level = var_bs.getbits(6);
    return var_ret;
}

int TrickPlayBoxRecord::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(pic_type, 2);
    var_bs.putbits(dependency_level, 6);
    return var_ret;
}

int SampleDependencyTypeBoxRecord::get(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    is_leading = var_bs.getbits(2);
    sample_depends_on = var_bs.getbits(2);
    sample_is_depended_on = var_bs.getbits(2);
    sample_has_redundancy = var_bs.getbits(2);
    return var_ret;
}

int SampleDependencyTypeBoxRecord::put(IBitstream &var_bs) {
    int var_ret = 0;
    var_bs.align(8);
    var_bs.putbits(is_leading, 2);
    var_bs.putbits(sample_depends_on, 2);
    var_bs.putbits(sample_is_depended_on, 2);
    var_bs.putbits(sample_has_redundancy, 2);
    return var_ret;
}

int SSFLIVE_BODY::get(IBitstream &var_bs, unsigned int vers) {
    int var_ret = 0;
    var_bs.align(8);
    
		    version = vers;
	 
    FragmentAbsoluteTime_0 = var_bs.getbits(32);
    if (1==vers) {
        FragmentAbsoluteTime = var_bs.getbits(32);
    }
    
    FragmentDuration_0 = var_bs.getbits(32);
    if (1==vers) {
        FragmentDuration = var_bs.getbits(32);
    }
    
    return var_ret;
}

int SSFLIVE_BODY::put(IBitstream &var_bs, unsigned int vers) {
    int var_ret = 0;
    var_bs.align(8);
    
		    version = vers;
	 
    var_bs.putbits(FragmentAbsoluteTime_0, 32);
    if (1==vers) {
        var_bs.putbits(FragmentAbsoluteTime, 32);
    }
    
    var_bs.putbits(FragmentDuration_0, 32);
    if (1==vers) {
        var_bs.putbits(FragmentDuration, 32);
    }
    
    return var_ret;
}

__ALX_END_NAMESPACE
