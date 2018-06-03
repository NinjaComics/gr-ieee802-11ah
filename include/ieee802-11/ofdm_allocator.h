#ifndef INCLUDED_OFDM_ALLOCATOR_H
#define INCLUDED_OFDM_ALLOCATOR_H

#include <ieee802-11/api.h>
#include <gnuradio/block.h>

namespace gr {
namespace ieee802_11 {

class IEEE802_11_API ofdm_allocator : virtual public block
{
public:

	typedef boost::shared_ptr<ofdm_allocator> sptr;

	// TODO finish IO
	static sptr make(std::vector<uint8_t> ofdm_alloc);
};

}  // namespace ieee802_11
}  // namespace gr

#endif //"INCLUDED_OFDM_ALLOCATOR_H"