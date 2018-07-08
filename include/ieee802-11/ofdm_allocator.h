/*
 * Copyright (C) 2018 David Zwart <d.j.zwart@student.tudelft.nl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef INCLUDED_OFDM_ALLOCATOR_H
#define INCLUDED_OFDM_ALLOCATOR_H

#include <ieee802-11/api.h>
#include <gnuradio/tagged_stream_block.h>

namespace gr {
namespace ieee802_11 {
	
	class IEEE802_11_API ofdm_allocator : virtual public tagged_stream_block
	{
		public:
			typedef boost::shared_ptr<ofdm_allocator> sptr;

			virtual std::string len_tag_key() = 0;
			virtual const int fft_len() = 0;
			virtual std::vector<std::vector<int> > occupied_carriers() = 0;

			static sptr make(
				int fft_len,
				const std::vector<std::vector<int> > &occupied_carriers,
				const std::vector<std::vector<int> > &pilot_carriers,
				const std::vector<std::vector<gr_complex> > &pilot_symbols,
				const std::vector<std::vector<gr_complex> > &sync_words,
				const std::string &len_tag_key = "packet_len",
				const bool output_is_shifted=true
			);
	};

}  // namespace ieee802_11
}  // namespace gr

#endif //"INCLUDED_OFDM_ALLOCATOR_H"