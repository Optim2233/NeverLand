## GitHub Copilot Chat

- Extension: 0.33.3 (prod)
- VS Code: 1.106.3 (bf9252a2fb45be6893dd8870c0bf37e2e1766d61)
- OS: win32 10.0.22631 x64
- GitHub Account: Optim2233

## Network

User Settings:
```json
  "github.copilot.advanced.debug.useElectronFetcher": true,
  "github.copilot.advanced.debug.useNodeFetcher": false,
  "github.copilot.advanced.debug.useNodeFetchFetcher": true
```

Connecting to https://api.github.com:
- DNS ipv4 Lookup: 20.205.243.168 (11 ms)
- DNS ipv6 Lookup: Error (10 ms): getaddrinfo ENOENT api.github.com
- Proxy URL: None (3 ms)
- Electron fetch (configured): timed out after 10 seconds
- Node.js https: Error (229 ms): Error: read ECONNRESET
    at TLSWrap.onStreamRead (node:internal/stream_base_commons:216:20)
- Node.js fetch: Error (164 ms): TypeError: fetch failed
    at node:internal/deps/undici/undici:13510:13
    at processTicksAndRejections (node:internal/process/task_queues:105:5)
    at b3._fetch (c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4418:24712)
    at c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4450:190
    at Zy.h (file:///c:/Users/Thura%20Htet/AppData/Local/Programs/Microsoft%20VS%20Code/resources/app/out/vs/workbench/api/node/extensionHostProcess.js:114:41645)
    at RG.handleItemSelection (c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4043:7909)
  Error: read ECONNRESET
      at TLSWrap.onStreamRead (node:internal/stream_base_commons:216:20)

Connecting to https://api.githubcopilot.com/_ping:
- DNS ipv4 Lookup: 140.82.112.22 (242 ms)
- DNS ipv6 Lookup: Error (552 ms): getaddrinfo ENOTFOUND api.githubcopilot.com
- Proxy URL: None (9 ms)
- Electron fetch (configured): HTTP 200 (1878 ms)
- Node.js https: HTTP 200 (1333 ms)
- Node.js fetch: HTTP 200 (1662 ms)

Connecting to https://copilot-proxy.githubusercontent.com/_ping:
- DNS ipv4 Lookup: 138.91.182.224 (297 ms)
- DNS ipv6 Lookup: Error (607 ms): getaddrinfo ENOENT copilot-proxy.githubusercontent.com
- Proxy URL: None (41 ms)
- Electron fetch (configured): timed out after 10 seconds
- Node.js https: Error (271 ms): AggregateError: 
    at internalConnectMultiple (node:net:1134:18)
    at afterConnectMultiple (node:net:1715:7)
  Error: connect ETIMEDOUT 138.91.182.224:443
      at createConnectionError (node:net:1678:14)
      at Timeout.internalConnectMultipleTimeout (node:net:1737:38)
      at listOnTimeout (node:internal/timers:590:11)
      at processTimers (node:internal/timers:523:7)
  Error: connect ENETUNREACH 64:ff9b::8a5b:b6e0:443
      at createConnectionError (node:net:1678:14)
      at afterConnectMultiple (node:net:1708:16)
- Node.js fetch: Error (277 ms): TypeError: fetch failed
    at node:internal/deps/undici/undici:13510:13
    at processTicksAndRejections (node:internal/process/task_queues:105:5)
    at b3._fetch (c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4418:24712)
    at c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4450:190
    at Zy.h (file:///c:/Users/Thura%20Htet/AppData/Local/Programs/Microsoft%20VS%20Code/resources/app/out/vs/workbench/api/node/extensionHostProcess.js:114:41645)
    at RG.handleItemSelection (c:\Users\Thura Htet\.vscode\extensions\github.copilot-chat-0.33.3\dist\extension.js:4043:7909)
  AggregateError: 
      at internalConnectMultiple (node:net:1134:18)
      at afterConnectMultiple (node:net:1715:7)
    Error: connect ETIMEDOUT 138.91.182.224:443
        at createConnectionError (node:net:1678:14)
        at Timeout.internalConnectMultipleTimeout (node:net:1737:38)
        at listOnTimeout (node:internal/timers:590:11)
        at processTimers (node:internal/timers:523:7)
    Error: connect ENETUNREACH 64:ff9b::8a5b:b6e0:443
        at createConnectionError (node:net:1678:14)
        at afterConnectMultiple (node:net:1708:16)

Connecting to https://github.com: HTTP 200 (692 ms)
Connecting to https://copilot-telemetry.githubusercontent.com/_ping: Error (264 ms): AggregateError: 
    at internalConnectMultiple (node:net:1134:18)
    at afterConnectMultiple (node:net:1715:7)
  Error: connect ETIMEDOUT 140.82.112.22:443
      at createConnectionError (node:net:1678:14)
      at Timeout.internalConnectMultipleTimeout (node:net:1737:38)
      at listOnTimeout (node:internal/timers:590:11)
      at processTimers (node:internal/timers:523:7)
  Error: connect ENETUNREACH 64:ff9b::8c52:7016:443
      at createConnectionError (node:net:1678:14)
      at afterConnectMultiple (node:net:1708:16)

Number of system certificates: 38

## Documentation

In corporate networks: [Troubleshooting firewall settings for GitHub Copilot](https://docs.github.com/en/copilot/troubleshooting-github-copilot/troubleshooting-firewall-settings-for-github-copilot).