/* @mediagen - experiment appveyor linux and win 0.12 -
 *
 * mp4i_ext.h
 * 
 * This file was automatically generated
 * from the source file:
 *     'mp4i_ext.fl'
 *
 * For information visit the Flavor Web site at:
 *     http://flavor.sourceforge.net
 *
 * -- Do not edit by hand --
 *
 */

#ifndef var_mp4i_ext_h_
#define var_mp4i_ext_h_

// initial size of parsable arrays: 64

// pragma: array=256
// pragma: get
#include "mp4.h"

const unsigned int box_ILST = BOX( 'i', 'l', 's', 't' );
const unsigned int box_iNAM = BOX( 0xA9, 'n', 'a', 'm' );
const unsigned int box_iCMT = BOX( 0xA9, 'c', 'm', 't' );
const unsigned int box_iDAY = BOX( 0xA9, 'd', 'a', 'y' );
const unsigned int box_iART = BOX( 0xA9, 'A', 'R', 'T' );
const unsigned int box_iTRK = BOX( 0xA9, 't', 'r', 'k' );
const unsigned int box_iALB = BOX( 0xA9, 'a', 'l', 'b' );
const unsigned int box_iCOM = BOX( 0xA9, 'c', 'o', 'm' );
const unsigned int box_iWRT = BOX( 0xA9, 'w', 'r', 't' );
const unsigned int box_iTOO = BOX( 0xA9, 't', 'o', 'o' );
const unsigned int box_iCPY = BOX( 0xA9, 'c', 'p', 'y' );
const unsigned int box_iDES = BOX( 0xA9, 'd', 'e', 's' );
const unsigned int box_iGEN = BOX( 0xA9, 'g', 'e', 'n' );
const unsigned int box_iGRP = BOX( 0xA9, 'g', 'r', 'p' );
const unsigned int box_iENC = BOX( 0xA9, 'e', 'n', 'c' );
const unsigned int box_aART = BOX( 'a', 'A', 'R', 'T' );
const unsigned int box_PGAP = BOX( 'p', 'g', 'a', 'p' );
const unsigned int box_GNRE = BOX( 'g', 'n', 'r', 'e' );
const unsigned int box_DISK = BOX( 'd', 'i', 's', 'k' );
const unsigned int box_TRKN = BOX( 't', 'r', 'k', 'n' );
const unsigned int box_TMPO = BOX( 't', 'm', 'p', 'o' );
const unsigned int box_CPIL = BOX( 'c', 'p', 'i', 'l' );
const unsigned int box_COVR = BOX( 'c', 'o', 'v', 'r' );
const unsigned int box_iSpecificInfo = BOX( '-', '-', '-', '-' );
const unsigned int box_DATA = BOX( 'd', 'a', 't', 'a' );
const unsigned int box_CHAP = BOX( 'c', 'h', 'a', 'p' );


__ALX_BEGIN_NAMESPACE


class ilst_box {
public:
    unsigned int subtype;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

class data_box : public FullBox {
public:
    unsigned int reserved;
    public: virtual int get(IBitstream &var_bs);
    public: virtual int put(IBitstream &var_bs);
};

__ALX_END_NAMESPACE


#endif /* ! var_mp4i_ext_h_ */
