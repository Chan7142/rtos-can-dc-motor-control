function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/Discrete State-Space */
	this.urlHashMap["BLDC_M_sim:21"] = "Subsystem.c:44,106&Subsystem.h:42";
	/* <S1>/Gain */
	this.urlHashMap["BLDC_M_sim:10"] = "Subsystem.c:52";
	/* <S1>/Saturation */
	this.urlHashMap["BLDC_M_sim:27"] = "Subsystem.c:83,92";
	/* <S1>/Scope */
	this.urlHashMap["BLDC_M_sim:23"] = "msg=rtwMsg_reducedBlock&block=BLDC_M_sim:23";
	/* <S1>/Scope1 */
	this.urlHashMap["BLDC_M_sim:25"] = "msg=rtwMsg_reducedBlock&block=BLDC_M_sim:25";
	/* <S1>/Scope2 */
	this.urlHashMap["BLDC_M_sim:26"] = "msg=rtwMsg_reducedBlock&block=BLDC_M_sim:26";
	/* <S1>/Scope3 */
	this.urlHashMap["BLDC_M_sim:39"] = "msg=rtwMsg_reducedBlock&block=BLDC_M_sim:39";
	/* <S1>/Sum */
	this.urlHashMap["BLDC_M_sim:8"] = "Subsystem.c:51";
	/* <S1>/Sum1 */
	this.urlHashMap["BLDC_M_sim:9"] = "Subsystem.c:55";
	/* <S2>/Derivative Gain */
	this.urlHashMap["BLDC_M_sim:7:1684"] = "Subsystem.c:67";
	/* <S2>/Integral Gain */
	this.urlHashMap["BLDC_M_sim:7:1683"] = "Subsystem.c:63";
	/* <S2>/Integrator */
	this.urlHashMap["BLDC_M_sim:7:1685"] = "Subsystem.c:62,128&Subsystem.h:43";
	/* <S2>/Proportional Gain */
	this.urlHashMap["BLDC_M_sim:7:1682"] = "Subsystem.c:59";
	/* <S2>/Sum */
	this.urlHashMap["BLDC_M_sim:7:1681"] = "Subsystem.c:77";
	/* <S3>/DTDup */
	this.urlHashMap["BLDC_M_sim:7:1691"] = "msg=rtwMsg_reducedBlock&block=BLDC_M_sim:7:1691";
	/* <S3>/Diff */
	this.urlHashMap["BLDC_M_sim:7:1690"] = "Subsystem.c:79";
	/* <S3>/TSamp */
	this.urlHashMap["BLDC_M_sim:7:1688"] = "Subsystem.c:70,72";
	/* <S3>/UD */
	this.urlHashMap["BLDC_M_sim:7:1689"] = "Subsystem.c:78,131&Subsystem.h:44";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Subsystem"};
	this.sidHashMap["Subsystem"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "BLDC_M_sim:13"};
	this.sidHashMap["BLDC_M_sim:13"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "BLDC_M_sim:7"};
	this.sidHashMap["BLDC_M_sim:7"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "BLDC_M_sim:7:1686"};
	this.sidHashMap["BLDC_M_sim:7:1686"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S1>/theta"] = {sid: "BLDC_M_sim:14"};
	this.sidHashMap["BLDC_M_sim:14"] = {rtwname: "<S1>/theta"};
	this.rtwnameHashMap["<S1>/speed_rad"] = {sid: "BLDC_M_sim:16"};
	this.sidHashMap["BLDC_M_sim:16"] = {rtwname: "<S1>/speed_rad"};
	this.rtwnameHashMap["<S1>/ref"] = {sid: "BLDC_M_sim:29"};
	this.sidHashMap["BLDC_M_sim:29"] = {rtwname: "<S1>/ref"};
	this.rtwnameHashMap["<S1>/Demux"] = {sid: "BLDC_M_sim:24"};
	this.sidHashMap["BLDC_M_sim:24"] = {rtwname: "<S1>/Demux"};
	this.rtwnameHashMap["<S1>/Discrete PID Controller"] = {sid: "BLDC_M_sim:7"};
	this.sidHashMap["BLDC_M_sim:7"] = {rtwname: "<S1>/Discrete PID Controller"};
	this.rtwnameHashMap["<S1>/Discrete State-Space"] = {sid: "BLDC_M_sim:21"};
	this.sidHashMap["BLDC_M_sim:21"] = {rtwname: "<S1>/Discrete State-Space"};
	this.rtwnameHashMap["<S1>/Gain"] = {sid: "BLDC_M_sim:10"};
	this.sidHashMap["BLDC_M_sim:10"] = {rtwname: "<S1>/Gain"};
	this.rtwnameHashMap["<S1>/Mux"] = {sid: "BLDC_M_sim:22"};
	this.sidHashMap["BLDC_M_sim:22"] = {rtwname: "<S1>/Mux"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "BLDC_M_sim:27"};
	this.sidHashMap["BLDC_M_sim:27"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Scope"] = {sid: "BLDC_M_sim:23"};
	this.sidHashMap["BLDC_M_sim:23"] = {rtwname: "<S1>/Scope"};
	this.rtwnameHashMap["<S1>/Scope1"] = {sid: "BLDC_M_sim:25"};
	this.sidHashMap["BLDC_M_sim:25"] = {rtwname: "<S1>/Scope1"};
	this.rtwnameHashMap["<S1>/Scope2"] = {sid: "BLDC_M_sim:26"};
	this.sidHashMap["BLDC_M_sim:26"] = {rtwname: "<S1>/Scope2"};
	this.rtwnameHashMap["<S1>/Scope3"] = {sid: "BLDC_M_sim:39"};
	this.sidHashMap["BLDC_M_sim:39"] = {rtwname: "<S1>/Scope3"};
	this.rtwnameHashMap["<S1>/Sum"] = {sid: "BLDC_M_sim:8"};
	this.sidHashMap["BLDC_M_sim:8"] = {rtwname: "<S1>/Sum"};
	this.rtwnameHashMap["<S1>/Sum1"] = {sid: "BLDC_M_sim:9"};
	this.sidHashMap["BLDC_M_sim:9"] = {rtwname: "<S1>/Sum1"};
	this.rtwnameHashMap["<S1>/input"] = {sid: "BLDC_M_sim:28"};
	this.sidHashMap["BLDC_M_sim:28"] = {rtwname: "<S1>/input"};
	this.rtwnameHashMap["<S1>/theta_hat"] = {sid: "BLDC_M_sim:31"};
	this.sidHashMap["BLDC_M_sim:31"] = {rtwname: "<S1>/theta_hat"};
	this.rtwnameHashMap["<S1>/speed_rad_hat"] = {sid: "BLDC_M_sim:32"};
	this.sidHashMap["BLDC_M_sim:32"] = {rtwname: "<S1>/speed_rad_hat"};
	this.rtwnameHashMap["<S1>/d_hat"] = {sid: "BLDC_M_sim:33"};
	this.sidHashMap["BLDC_M_sim:33"] = {rtwname: "<S1>/d_hat"};
	this.rtwnameHashMap["<S2>/u"] = {sid: "BLDC_M_sim:7:1"};
	this.sidHashMap["BLDC_M_sim:7:1"] = {rtwname: "<S2>/u"};
	this.rtwnameHashMap["<S2>/Derivative Gain"] = {sid: "BLDC_M_sim:7:1684"};
	this.sidHashMap["BLDC_M_sim:7:1684"] = {rtwname: "<S2>/Derivative Gain"};
	this.rtwnameHashMap["<S2>/Differentiator"] = {sid: "BLDC_M_sim:7:1686"};
	this.sidHashMap["BLDC_M_sim:7:1686"] = {rtwname: "<S2>/Differentiator"};
	this.rtwnameHashMap["<S2>/Integral Gain"] = {sid: "BLDC_M_sim:7:1683"};
	this.sidHashMap["BLDC_M_sim:7:1683"] = {rtwname: "<S2>/Integral Gain"};
	this.rtwnameHashMap["<S2>/Integrator"] = {sid: "BLDC_M_sim:7:1685"};
	this.sidHashMap["BLDC_M_sim:7:1685"] = {rtwname: "<S2>/Integrator"};
	this.rtwnameHashMap["<S2>/Proportional Gain"] = {sid: "BLDC_M_sim:7:1682"};
	this.sidHashMap["BLDC_M_sim:7:1682"] = {rtwname: "<S2>/Proportional Gain"};
	this.rtwnameHashMap["<S2>/Sum"] = {sid: "BLDC_M_sim:7:1681"};
	this.sidHashMap["BLDC_M_sim:7:1681"] = {rtwname: "<S2>/Sum"};
	this.rtwnameHashMap["<S2>/y"] = {sid: "BLDC_M_sim:7:10"};
	this.sidHashMap["BLDC_M_sim:7:10"] = {rtwname: "<S2>/y"};
	this.rtwnameHashMap["<S3>/U"] = {sid: "BLDC_M_sim:7:1687"};
	this.sidHashMap["BLDC_M_sim:7:1687"] = {rtwname: "<S3>/U"};
	this.rtwnameHashMap["<S3>/DTDup"] = {sid: "BLDC_M_sim:7:1691"};
	this.sidHashMap["BLDC_M_sim:7:1691"] = {rtwname: "<S3>/DTDup"};
	this.rtwnameHashMap["<S3>/Diff"] = {sid: "BLDC_M_sim:7:1690"};
	this.sidHashMap["BLDC_M_sim:7:1690"] = {rtwname: "<S3>/Diff"};
	this.rtwnameHashMap["<S3>/TSamp"] = {sid: "BLDC_M_sim:7:1688"};
	this.sidHashMap["BLDC_M_sim:7:1688"] = {rtwname: "<S3>/TSamp"};
	this.rtwnameHashMap["<S3>/UD"] = {sid: "BLDC_M_sim:7:1689"};
	this.sidHashMap["BLDC_M_sim:7:1689"] = {rtwname: "<S3>/UD"};
	this.rtwnameHashMap["<S3>/Y"] = {sid: "BLDC_M_sim:7:1692"};
	this.sidHashMap["BLDC_M_sim:7:1692"] = {rtwname: "<S3>/Y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
