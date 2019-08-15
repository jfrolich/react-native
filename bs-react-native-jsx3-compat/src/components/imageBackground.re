[@react.component]
let make =
    (
      ~onError=?,
      ~onLayout=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~resizeMode=?,
      ~source,
      ~style=?,
      ~imageStyle=?,
      ~testID=?,
      ~resizeMethod=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~blurRadius=?,
      ~capInsets=?,
      ~defaultSource=?,
      ~onPartialLoad=?,
      ~onProgress=?,
      ~children=?,
    ) =>
  <ReactNative.ImageBackground
    imageStyle=?{imageStyle->Belt.Option.map(Obj.magic)}
    ?onError
    ?onLayout
    ?onLoad
    ?onLoadEnd
    ?onLoadStart
    ?resizeMode
    source={source->Image.encodeSource}
    ?style
    ?testID
    ?resizeMethod
    ?accessibilityLabel
    ?accessible
    ?blurRadius
    capInsets=?{Types.toEdgeInsets(capInsets)}
    defaultSource=?{defaultSource->Belt.Option.map(Image.encodeDefaultSource)}
    ?onPartialLoad
    onProgress=?{
      onProgress->Belt.Option.map((cb, e) => cb(Image.Event.progress(e)))
    }>
    {children->Belt.Option.getWithDefault(React.null)}
  </ReactNative.ImageBackground>;