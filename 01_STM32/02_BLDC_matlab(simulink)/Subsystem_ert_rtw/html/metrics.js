function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	size: 40};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	size: 4};
	 this.metricsArray.var["rtU"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	size: 24};
	 this.metricsArray.var["rtY"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	size: 32};
	 this.metricsArray.fcn["Subsystem_initialize"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Subsystem_step"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\Subsystem_ert_rtw\\Subsystem.c",
	stack: 88,
	stackTotal: 88};
	 this.metricsArray.fcn["memcpy"] = {file: "C:\\Program Files\\MATLAB\\R2016a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
