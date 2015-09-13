﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
GacUI::HTrackerTemplate

This file is generated by: Vczh GacUI Resource Code Generator
***********************************************************************/

#include <math.h>
#include "GacStudioUI.h"

namespace darkskin
{
	// #region CLASS_MEMBER_GUIEVENT_HANDLER (DO NOT PUT OTHER CONTENT IN THIS #region.)

	void HTrackerTemplate::OnHandleMouseMove(GuiGraphicsComposition* sender, vl::presentation::compositions::GuiMouseEventArgs& arguments)
	{
		if (draggingHandle)
		{
			vint totalPixels = handle->GetParent()->GetBounds().Width();
			vint currentOffset = handle->GetBounds().Left();
			vint newOffset = currentOffset + (arguments.x - draggingStartLocation.x);
			vint totalSize = GetTotalSize();
			double ratio = (double)newOffset / totalPixels;
			vint newPosition = (vint)(ratio * totalSize);

			vint offset1 = (vint)(((double)newPosition / totalSize) * totalPixels);
			vint offset2 = vint(((double)(newPosition + 1) / totalSize) * totalPixels);
			vint delta1 = abs((int)(offset1 - newOffset));
			vint delta2 = abs((int)(offset2 - newOffset));

			if(delta1 < delta2)
			{
				GetCommands()->SetPosition(newPosition);
			}
			else
			{
				GetCommands()->SetPosition(newPosition + 1);
			}
		}
	}

	// #endregion CLASS_MEMBER_GUIEVENT_HANDLER

	HTrackerTemplate::HTrackerTemplate()
	{
		draggingHandle = false;
		InitializeComponents();
	}
}
