# SIEM - Security Information and Event Management
 1. Collect data from sources
 2. Aggregate data
 3. Discover and detect threats
 4. Identify breaches and investigate alerts

## Log sources categorization
 1. **Host-Centric Log Sources**: These log are sources tjhat the capture events that occurred within or related to the host. Some log sources that generate host-centric logs are Windows Event logs, Sysmon, Osquery, etc. Some examples of host-centric logs are:
    * A user accessing a file
    * A user attempting to authenticate
    * A process Execution Activity
    * A process adding/editing/deleting a registry key or value.
    * Powershell execution.
 2. **Network-Centric Log Sources**: Network-related logs are generated when the hosts communicate with each other or access the internet to visit a website. Some network-based protocols are SSH, VPN, HTTP/s, FTP etc. Examples of such events are:
    * SSH connection
    * A file being access via FTP
    * Web traffic
    * A user accessing company's resources through VPN.
    * Network file sharing Activity

## Log ingestion
Each SIEM solution has its own way to ingesting the logs. Some common methods used by these SIEM solutions are below:
 1. **Agent/Forwarder**: These SIEM solutions provide a lightweight tool called an agent (forwarder by Splunk) that gets installed in the Endpoint. It is configured to capture all the important logs and send them to the SIEM server.
 2. **Syslog**: Syslog is a widely used protocol to collect data from various systems like web server, databases, etc., are sent real-time data to the centralized destination.
 3. **Manual Upload**: Some SIEM solutions, like Splunk, ELK (Elasticsearch, Logstash, and Kibana: These are three open-source tools that are commonly used together to collect, store, analysis, and visualize data.), etc., allow users to ingest offline data for quick analysis. Once the data is ingested, it is normalized and made available for analysis.
 4. **Port-Forwarding**: SIEM solutions can be configured to listen on certain port, and then the endpoints forward the data to the SIEM instance on the listening port.

## SIEM Capabilities
SIEM is one major component of a Security Operations Center (SOC) ecosystem, as mentiond below. SIEM starts by collecting logs and examining if any event/flow has matched the condition set in the rule or crossed a cetain threshold.

### Component of Security Operations Center (SOC) ecosystems:
 * Ticketing
 * Log Collection
 * Knowledge Base
 * Research and Development
 * Aggegation and Correlation
 * Threat Intelligence
 * SIEM (Security Information and Event Management)
 * Reporting

### Some of common capabilities of SIEM:
 * Correlation between events from different log sources.
 * Providing visibility on both Host-centric and Network-centric activities
 * Allow analysts to investigate the latest threats and timely responses.
 * Hunt for threats that are not detected by the rules in place.

## SOC Analyst Responsibilities
SOC Analysts utilize SIEM solutions in order to have better visibility of what is happening within the network. Some of their responsibilities:
 * Monitoring and Investigating
 * Identifying False positives
 * Tuning Rules which are causing the noise or False positives
 * Reporting and Compliance
 * Identifying blind spots in the network visibility and covering them.


> Source: https://tryhackme.com/room/introtosiem
