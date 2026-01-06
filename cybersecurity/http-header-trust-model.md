# HTTP header trust model

## 1. What an HTTP header is?
 * Headers are:
   * key-value metadata
   * attached to a request
 * They are:
   * plain text
   * client-supplied
 * They are not:
   * [not] validated by HTTP itself. *not validated by HTTP itself*

## 2. Who creates headers? (authority boundary)
Headers are created by:
 * browsers
 * scripts
 * libraries
 * tools (`curl`, `wget`)
 * proxies

**Servers do not create requests headers.*

So the trust question becomes obvious:
> Why trust something created by the other side?

## 3. Who reads headers
Headers are read by:
 * web frameworks
 * middleware
 * application code
 * business logic

Example:
```php
if ($_SERVER['HTTP_SEC_CH_UA_PLATFORM'] === 'Windows') {
    enableFeature();
}
```

## 4. What HTTP itself guarantees (almost nothing)
HTTP gurantees:
 * header syntax correctness
 * message framing
HTTP does **not** guarantee:
 * honesty
 * accuracy
 * consistency
 * origin truth

This is not a flaw. This is by design.

## 5. The single rule that defines the trust model
This is the **entire trust model**, stated precisely:
> **Every HTTP request header is a claim, not a fact.**
That's it.

