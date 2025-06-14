# Operational Security (OPSEC)

Operational Security (OPSEC) is a term originally coined in the military to refer to tjhe porcess of protecting sensitive information and operations from adversaries. The goal is to identify and eliminate potential vulnerabilities before the attacker can learn their identity.

 * OPSEC is a process to *identify, control* and *protect* any information related to the planning and execution of our activites.


## Definition provided by NIST:
Systematic and proven process by which potential adversaries can be denied information about capabilities and intentions by indenfiying, controlling, and protecting generally unclassified evidence of the planning and execution of sensitive activities. The OPSEC process has five steps:
 1. Identify critical information: *Critical Information includes, but is not limited to, red team's intentions, capabilities, activities and limitations.*
 2. Analysis threats: *Thread analysis referes to identifying potential adversaries and their intentions and capabilities.*
 3. Analyse vulnerabilites: *An OPSEC vulnerability exists when an adversary can obtain critical information, analyse the findings, and act in a way that would affect the plans.*
 4. Assess risks: *Risk assessment requires learning the possibility of an event taking place along with the expected cost of that event.*
 5. Apply appropriate countermeasures: *Countermeasures are designed to prevent an adversary from detecting critical information, provide an alternative interpretation of critical information or indicators (deception), or deny the adversary's collection system.*

 * **Threat Analysis** - Threat analysis referes to identifying potential adversaries and their intentions and capabilities. Threat analysis aims to answer the following questions:
   * Who is the adversary?
   * What are the adversary's goals?
   * What tactics, techniques, and procedures does the adversary use?
   * What critical information has the adversary obtained, if any?
```bash
threat = adversary + intent + capability
```
 * **Vernability Analysis** - An OPSEC vulnerability exist when an adversary can obtain critical information, analyse the findings, and act in a way that would affect the plans.

 * **Countermeasures** - Countermeasures are designed to prevent an adversary from detecting critical information, provide an alternative interpretation of critical information or dindicators (decption), or deny the adversary's collection system.

***OPSEC is not a solution or a set of rules; OPSEC is a five-step process to deny adversaries from gaining access to any critical information***

In the context of cyber security, when malicous actors fail to follow proper OPSEC practices, they might leave digital traces that can be pieced together to reveal their identity. Some common OPSEC mistakes include:
 * Resuing usernames, email addresses, or account handles across multiple platforms. One might assume that anyone trying to cover their tracks would remove such obvious and incriminating information, but sometimes, it's due to vanity or simply forgetfulness.
 * Using identifiable metadata in code, documents, or images, which may reveal personal information like device names, GPS coordinations, or timestamps.
 * Posting publicly on forums or GitHub with details that tie back to their real identity or refveal their location or habits.
 * Failing to use VPN or proxy while conducting malicious activites allows law enforcement to track their real IP address.

> Source: https://tryhackme.com/room/adventofcyber2024
