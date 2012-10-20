///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2011 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/image.hpp
/// @date 2011-10-06 / 2011-10-06
/// @author Christophe Riccio
///
/// @defgroup core_image Image 
/// @ingroup core
/// 
/// Image1D 
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_image
#define GLI_CORE_image GLI_VERSION

#include "storage.hpp"
#include "format.hpp"
#include "header.hpp"

namespace gli
{
	class image
	{
	public:
		typedef detail::storage::size_type size_type;
		typedef detail::storage::dimensions4_type dimensions_type;

		image();
		image(
			image const & Image);

		/// Reference an exiting texture storage constructor
		/// 
		/// @param Offset Data offset in the texture storage expressed in bytes.
		explicit image(
			shared_ptr<detail::storage> const & Storage,
			detail::view const & View);

		/// Allocate a new texture storage constructor
		template <typename genType>
		explicit image(
			dimensions_type const & Dimensions,
			std::vector<genType> const & Data);

		/// Allocate a new texture storage constructor and copy data
		explicit image(
			dimensions_type const & Dimensions,
			size_type const & BlockSize,
			dimensions_type const & BlockDimensions);

		/// TODO: Add a contructor with the format. (Not defined)
		explicit image(
			dimensions_type const & Dimensions,
			format const & Format);

		~image();

		/// Allocate the storage for the image of exactly the memory size required by the image 
		//bool resize();

		image & operator=(image const & Image);

		dimensions_type dimensions() const;

		bool empty() const;
		size_type size() const;

		template <typename genType>
		genType * data();
		template <typename genType>
		genType const * const data() const;

	private:
		size_type linearAddressing(
			size_type const & Layer, 
			size_type const & Face, 
			size_type const & Level) const;

		shared_ptr<detail::storage> Storage;
		detail::view View;
	};

	bool operator== (image const & ImageA, image const & ImageB);
	bool operator!= (image const & ImageA, image const & ImageB);
}//namespace gli

#include "image.inl"

#endif//GLI_CORE_image
