# clicking-phising-link.md
# What to Do After Clicking a Phising Link

---

# 🛡️ Phishing Incident Response Checklist (Generic)

## 1️⃣ **Immediate Containment**

☐ Disconnect from the Internet (turn off Wi-Fi / unplug cable)
☐ Do *not* enter any data or credentials on the suspicious page
☐ Close the phishing tab/browser immediately
☐ Take a screenshot or note the link (for reporting)

---

## 2️⃣ **Session Termination**

☐ Log out from all critical accounts (email, banking, social, etc.)
☐ Reconnect to the Internet using a *trusted* connection
☐ Log in again from a *known safe device*
☐ Change your password for affected accounts
☐ Enable 2FA / MFA on all critical accounts
☐ Review and revoke unknown active sessions/devices

---

## 3️⃣ **Credential & Data Review**

☐ Ask: Did I enter any credentials on the fake site?
  ➡ If **yes**, treat them as compromised — change passwords everywhere used
☐ Check if any file was downloaded or run
  ➡ If **yes**, move to Step 4 (Malware Check)

---

## 4️⃣ **System & Malware Check**

☐ Run a full antivirus/antimalware scan
☐ Use additional scanners (e.g., Malwarebytes, ClamAV, Defender Offline)
☐ Review startup programs and browser extensions for unknown entries
☐ Remove or quarantine suspicious items
☐ Keep OS, browser, and AV updated

---

## 5️⃣ **Browser Cleanup**

☐ Clear cookies, cache, and site data
☐ Remove unfamiliar extensions
☐ Reset browser settings to default
☐ Disable “auto-fill passwords” temporarily

---

## 6️⃣ **Email Security Audit**

☐ Review mail filters and forwarding rules
☐ Delete any unknown forwarding addresses
☐ Check recovery options (email, phone) for tampering
☐ Remove unknown delegated accounts

---

## 7️⃣ **Report & Documentation**

☐ Report the phishing email or site to your provider (e.g., “Report Phishing” option)
☐ If at work, notify your security or IT department immediately
☐ Optionally report to your national **CERT / cybercrime unit**
☐ Keep a record of date, link, and actions taken

---

## 8️⃣ **Post-Incident Hardening**

☐ Update all software (OS, browser, plugins)
☐ Enable automatic updates
☐ Switch to a password manager
☐ Review 2FA setup for all critical services
☐ Avoid reusing passwords
☐ Learn to verify URLs before clicking (hover → domain inspection)

---

## 9️⃣ **Monitoring (Next 7–14 Days)**

☐ Watch for suspicious login alerts or password reset emails
☐ Check “Last account activity” where available
☐ Monitor bank statements and online accounts
☐ Use [haveibeenpwned.com](https://haveibeenpwned.com) to check for leaks
☐ Consider a credit freeze or alert if financial data may be at risk

---

## 🔟 **Final Option — Deep Clean (If Compromise Confirmed)**

☐ Backup essential personal data (photos, docs)
☐ Wipe and reinstall the OS from a trusted image
☐ Restore only clean data
☐ Change all credentials again after reinstallation

---

### 🧩 Optional Tools

| Purpose            | Recommended Tool                         | Notes                           |
| ------------------ | ---------------------------------------- | ------------------------------- |
| Malware scan       | Windows Defender / Malwarebytes / ClamAV | Always run offline or full scan |
| Process inspection | `ps`, `tasklist`, `top`, Autoruns        | Check startup entries           |
| Network activity   | `netstat -ano`, `ss -tupn`               | Identify suspicious connections |
| Browser cleaning   | Built-in browser reset tools             | Remove injected extensions      |
| Password audit     | Bitwarden / KeePassXC                    | Prevent reuse across sites      |

---
