$NetBSD$

--- Source/kwsys/SystemInformation.cxx.orig	2014-05-19 08:54:07.210501632 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -134,7 +134,7 @@ typedef int siginfo_t;
 # endif
 #endif
 
-#if defined(__linux) || defined (__sun)
+#if defined(__linux) || defined (__sun) || defined (__HAIKU__)
 # include <fenv.h>
 # include <sys/socket.h>
 # include <netdb.h>
@@ -4666,6 +4666,41 @@ bool SystemInformationImplementation::Qu
 }
 
 
+int32
+	get_rounded_cpu_speed(void)
+	{
+	uint32 topologyNodeCount = 0;
+	cpu_topology_node_info* topology = NULL;
+	get_cpu_topology_info(NULL, &topologyNodeCount);
+	if (topologyNodeCount != 0)
+		topology = new cpu_topology_node_info[topologyNodeCount];
+	get_cpu_topology_info(topology, &topologyNodeCount);
+
+	uint64 cpuFrequency = 0;
+	for (uint32 i = 0; i < topologyNodeCount; i++) {
+		if (topology[i].type == B_TOPOLOGY_CORE) {
+				cpuFrequency = topology[i].data.core.default_frequency;
+				break;
+		}
+	}
+	delete[] topology;
+
+	int target, frac, delta;
+	int freqs[] = { 100, 50, 25, 75, 33, 67, 20, 40, 60, 80, 10, 30, 70, 90 };
+	uint x;
+
+	target = cpuFrequency / 1000000;
+	frac = target % 100;
+	delta = -frac;
+
+	for (x = 0; x < sizeof(freqs) / sizeof(freqs[0]); x++) {
+		int ndelta = freqs[x] - frac;
+		if (abs(ndelta) < abs(delta))
+			delta = ndelta;
+	}
+	return target + delta;
+  }
+
 /** Querying for system information from Haiku OS */
 bool SystemInformationImplementation::QueryHaikuInfo()
 {
@@ -4675,7 +4710,7 @@ bool SystemInformationImplementation::Qu
   get_system_info(&info);
 
   this->NumberOfPhysicalCPU = info.cpu_count;
-  this->CPUSpeedInMHz = info.cpu_clock_speed / 1000000.0F;
+  this->CPUSpeedInMHz = get_rounded_cpu_speed();
 
   // Physical Memory
   this->TotalPhysicalMemory = (info.max_pages * B_PAGE_SIZE) / (1024 * 1024) ;
