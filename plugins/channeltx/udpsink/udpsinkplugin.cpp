///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "udpsinkplugin.h"

#include <QtPlugin>
#include "plugin/pluginapi.h"

#include "udpsinkgui.h"

const PluginDescriptor UDPSinkPlugin::m_pluginDescriptor = {
	QString("UDP Channel Sink"),
	QString("3.6.0"),
	QString("(c) Edouard Griffiths, F4EXB"),
	QString("https://github.com/f4exb/sdrangel"),
	true,
	QString("https://github.com/f4exb/sdrangel")
};

UDPSinkPlugin::UDPSinkPlugin(QObject* parent) :
	QObject(parent),
	m_pluginAPI(0)
{
}

const PluginDescriptor& UDPSinkPlugin::getPluginDescriptor() const
{
	return m_pluginDescriptor;
}

void UDPSinkPlugin::initPlugin(PluginAPI* pluginAPI)
{
	m_pluginAPI = pluginAPI;

	// register TCP Channel Source
	m_pluginAPI->registerTxChannel(UDPSinkGUI::m_channelID, this);
}

PluginGUI* UDPSinkPlugin::createTxChannel(const QString& channelName, DeviceSinkAPI *deviceAPI)
{
	if(channelName == UDPSinkGUI::m_channelID)
	{
	    UDPSinkGUI* gui = UDPSinkGUI::create(m_pluginAPI, deviceAPI);
//		deviceAPI->registerChannelInstance("sdrangel.channel.udpsrc", gui);
//		m_pluginAPI->addChannelRollup(gui);
		return gui;
	} else {
		return 0;
	}
}

void UDPSinkPlugin::createInstanceUDPSink(DeviceSinkAPI *deviceAPI)
{
    UDPSinkGUI::create(m_pluginAPI, deviceAPI);
//	deviceAPI->registerChannelInstance("sdrangel.channel.udpsrc", gui);
//	m_pluginAPI->addChannelRollup(gui);
}