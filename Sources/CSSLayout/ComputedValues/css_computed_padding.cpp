/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#include "CSSLayout/precomp.h"
#include "API/CSSLayout/ComputedValues/css_computed_padding.h"
#include "API/CSSLayout/ComputedValues/css_computed_values.h"

namespace clan
{

void CSSComputedPadding::compute(const CSSComputedValues &parent, CSSResourceCache *layout, float em_size, float ex_size)
{
	if (!parent.is_null())
	{
		const CSSComputedPadding &parent_padding = parent.get_padding();

		padding_width_left.compute(&parent_padding.padding_width_left, layout, em_size, ex_size);
		padding_width_top.compute(&parent_padding.padding_width_top, layout, em_size, ex_size);
		padding_width_right.compute(&parent_padding.padding_width_right, layout, em_size, ex_size);
		padding_width_bottom.compute(&parent_padding.padding_width_bottom, layout, em_size, ex_size);
	}
	else
	{
		padding_width_left.compute(0, layout, em_size, ex_size);
		padding_width_top.compute(0, layout, em_size, ex_size);
		padding_width_right.compute(0, layout, em_size, ex_size);
		padding_width_bottom.compute(0, layout, em_size, ex_size);
	}
}

}
