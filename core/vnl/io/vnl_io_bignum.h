// This is vxl/vnl/io/vnl_io_bignum.h
#ifndef vnl_io_bignum_h
#define vnl_io_bignum_h
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma interface
#endif
//:
// \file 
// \author Ian Scott
// \date 10-Oct-2001

#include <vnl/vnl_bignum.h>
class vsl_b_ostream;
class vsl_b_istream;

//: Binary save vnl_bignum to stream.
void vsl_b_write(vsl_b_ostream & os, vnl_bignum const& v);

//: Binary load vnl_bignum from stream.
void vsl_b_read(vsl_b_istream & is, vnl_bignum & v);

//: Print human readable summary of object to a stream
void vsl_print_summary(vcl_ostream & os, vnl_bignum const& b);

#endif // vnl_io_bignum_h
