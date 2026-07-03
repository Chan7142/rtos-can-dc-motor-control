function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	size: 136};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	size: 393};
	 this.metricsArray.var["rtX"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	size: 16};
	 this.metricsArray.fcn["BLDC_M_sim.c:rt_ertODEUpdateContinuousStates"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	stack: 176,
	stackTotal: -1};
	 this.metricsArray.fcn["BLDC_M_sim_derivatives"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["BLDC_M_sim_initialize"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["BLDC_M_sim_step"] = {file: "C:\\Users\\leesc\\Desktop\\rtos-can-bldc-motor-control\\01_STM32\\02_BLDC_matlab(simulink)\\BLDC_M_sim_ert_rtw\\BLDC_M_sim.c",
	stack: 52,
	stackTotal: -1};
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
