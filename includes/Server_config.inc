## The SilabServer jpu starts a socket server on the specified port, which can be used to load Silab trf, scn and odb data from any application.
## This server is required by the RoboTaxi Go server to load traffic information.
## Make sure the SilabServer.java file is placed in the <project>/java directory.

SCN.ODB = true;
TRF.ODB = true;
MOV.ODB = true;

DPUJava SilabServer
{
    Computer = {ASS};
    Index = 999;

    Class = SilabServer;
};

Connections =
{
	VDyn.X -> SilabServer.X,
	VDyn.Y -> SilabServer.Y,
	VDyn.yaw -> SilabServer.Yaw,

    ~Automation_Framework_LfE.active_lat_and_long -> SilabServer.AutomationActive,
	~Automation_Framework_LfE.standstill -> SilabServer.AutomationStandstill,

    # The following Automation Framework inputs are deactivated from the operator interface to avoid interferences
    SilabServer.AutomationActiveImpulse -> ~Automation_Framework_LfE.sim_long_lat_io,
    SilabServer.AutomationStandstillImpulse -> ~Automation_Framework_LfE.sim_standstill
};
