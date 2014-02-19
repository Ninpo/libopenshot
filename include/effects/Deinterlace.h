/**
 * @file
 * @brief Header file for De-interlace class
 * @author Jonathan Thomas <jonathan@openshot.org>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2013 OpenShot Studios, LLC
 * (http://www.openshotstudios.com). This file is part of
 * OpenShot Library (http://www.openshot.org), an open-source project
 * dedicated to delivering high quality video editing and animation solutions
 * to the world.
 *
 * OpenShot Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenShot Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenShot Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENSHOT_DEINTERLACE_EFFECT_H
#define OPENSHOT_DEINTERLACE_EFFECT_H

#include "../EffectBase.h"

#include <cmath>
#include <ctime>
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <tr1/memory>
#include "Magick++.h"
#include "../Color.h"
#include "../Exceptions.h"
#include "../Json.h"
#include "../KeyFrame.h"

using namespace std;

namespace openshot
{

	/**
	 * @brief This class uses the ImageMagick++ libraries, to de-interlace the image, which
	 * removes the EVEN or ODD horizontal lines (which represent different points of time).
	 *
	 * This is most useful when converting video made for traditional TVs to computers,
	 * which are not interlaced.
	 */
	class Deinterlace : public EffectBase
	{
	private:
		bool isOdd;

	public:

		/// Blank constructor, useful when using Json to load the effect properties
		Deinterlace();

		/// Default constructor
		Deinterlace(bool isOdd);

		/// @brief This method is required for all derived classes of EffectBase, and returns a
		/// modified openshot::Frame object
		///
		/// The frame object is passed into this method, and a frame_number is passed in which
		/// tells the effect which settings to use from it's keyframes (starting at 1).
		///
		/// @returns The modified openshot::Frame object
		/// @param frame The frame object that needs the effect applied to it
		/// @param frame_number The frame number (starting at 1) of the effect on the timeline.
		tr1::shared_ptr<Frame> GetFrame(tr1::shared_ptr<Frame> frame, int frame_number);

		/// Get and Set JSON methods
		string Json(); ///< Generate JSON string of this object
		void SetJson(string value) throw(InvalidJSON); ///< Load JSON string into this object
		Json::Value JsonValue(); ///< Generate Json::JsonValue for this object
		void SetJsonValue(Json::Value root); ///< Load Json::JsonValue into this object
	};

}

#endif