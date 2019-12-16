type methods = [
| `GET
| `POST
| `HEAD
| `DELETE
| `PATCH
| `PUT
| `OPTIONS
];

let stringOfMeth = (meth: methods) => 
  switch meth {
  | `GET => "GET"
  | `POST => "POST"
  | `HEAD => "HEAD"
  | `DELETE => "DELETE"
  | `PATCH => "PATCH"
  | `PUT => "PUT"
  | `OPTIONS => "OPTIONS"
  };

type informationalStatus = [
| `Continue
| `SwitchingProtocols
| `Processing
];

type successStatus = [
| `OK
| `Created
| `Accepted
| `NonAuthoritativeInformation
| `NoContent
| `ResetContent
| `PartialContent
| `MultiStatus
| `AlreadyReported
| `ImUsed
];

type redirectionStatus = [
| `MultipleChoices
| `MovedPermanently
| `Found
| `SeeOther
| `NotModified
| `UseProxy
| `SwitchProxy
| `TemporaryRedirect
| `ResumeIncomplete
];

type clientErrorStatus = [
| `BadRequest
| `Unauthorized
| `PaymentRequired
| `Forbidden
| `NotFound
| `MethodNotAllowed
| `NotAcceptable
| `ProxyAuthenticationRequired
| `RequestTimeout
| `Conflict
| `Gone
| `Length_required
| `PreconditionFailed
| `RequestEntityTooLarge
| `RequestUriTooLong
| `UnsupportedMediaType
| `RequestedRangeNotSatisfiable
| `ExpectationFailed
| `ImATeapot
| `MisdirectedRequest
| `EnhanceYourCalm
| `UnprocessableEntity
| `Locked
| `FailedDependency
| `UpgradeRequired
| `PreconditionRequired
| `TooManyRequests
| `RequestHeaderFieldsTooLarge
| `NoResponse
| `RetryWith
| `BlockedByWindowsParentalControls
| `ClientClosedRequest
];

type serverErrorStatus = [
| `InternalServerError
| `NotImplemented
| `BadGateway
| `ServiceUnavailable
| `GatewayTimeout
| `HttpVersionNotSupported
| `VariantAlsoNegotiates
| `InsufficientStorage
| `LoopDetected
| `BandwidthLimitExceeded
| `NotExtended
| `NetworkAuthenticationRequired
| `NetworkReadTimeoutError
| `NetworkConnectTimeoutError
];

type status = [
| informationalStatus
| successStatus
| redirectionStatus
| clientErrorStatus
| serverErrorStatus
]

type statusCode = [status | `Code(int)];

let codeOfStatus = (s: statusCode) => {
  switch s {
  // Information
  | `Continue => 100
  | `SwitchingProtocols => 101
  | `Processing => 102

  // Success
  | `OK => 200
  | `Created => 201
  | `Accepted => 202
  | `NonAuthoritativeInformation => 203
  | `NoContent=> 204
  | `ResetContent => 205
  | `PartialContent => 206
  | `MultiStatus => 207
  | `AlreadyReported => 208
  | `ImUsed => 226

  // Redirection
  | `MultipleChoices => 300
  | `MovedPermanently => 301
  | `Found => 302
  | `SeeOther => 303
  | `NotModified => 304
  | `UseProxy => 305
  | `SwitchProxy => 306
  | `TemporaryRedirect => 307
  | `ResumeIncomplete => 308

  // Client Error
  | `BadRequest => 400
  | `Unauthorized => 401
  | `PaymentRequired => 402
  | `Forbidden => 403
  | `NotFound => 404
  | `MethodNotAllowed => 405
  | `NotAcceptable => 406
  | `ProxyAuthenticationRequired => 407
  | `RequestTimeout => 408
  | `Conflict => 409
  | `Gone => 410
  | `Length_required => 411
  | `PreconditionFailed => 412
  | `RequestEntityTooLarge => 413
  | `RequestUriTooLong => 414
  | `UnsupportedMediaType => 415
  | `RequestedRangeNotSatisfiable => 416
  | `ExpectationFailed => 417
  | `ImATeapot => 418
  | `MisdirectedRequest => 421
  | `EnhanceYourCalm => 420
  | `UnprocessableEntity => 422
  | `Locked => 423
  | `FailedDependency => 424
  | `UpgradeRequired => 426
  | `PreconditionRequired => 428
  | `TooManyRequests => 429
  | `RequestHeaderFieldsTooLarge => 431
  | `NoResponse => 444
  | `RetryWith => 449
  | `BlockedByWindowsParentalControls => 450
  | `ClientClosedRequest => 499

  // Error
  | `InternalServerError => 500
  | `NotImplemented => 501
  | `BadGateway => 502
  | `ServiceUnavailable => 503
  | `GatewayTimeout => 504
  | `HttpVersionNotSupported => 505
  | `VariantAlsoNegotiates => 506
  | `InsufficientStorage => 507
  | `LoopDetected => 508
  | `BandwidthLimitExceeded => 509
  | `NotExtended => 510
  | `NetworkAuthenticationRequired => 511
  | `NetworkReadTimeoutError => 598
  | `NetworkConnectTimeoutError => 599

  | `Code(code) => code
  };
}