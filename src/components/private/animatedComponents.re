module View =
  ViewRe.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "AnimatedRe"] external view : ReasonReact.reactClass =
        "ViewRe";
      let view = view;
    }
  );

module Image =
  Image.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "AnimatedRe"] external view : ReasonReact.reactClass =
        "Image";
      let view = view;
    }
  );

module Text =
  Text.CreateComponent(
    {
      [@bs.module "react-native"] [@bs.scope "AnimatedRe"] external view : ReasonReact.reactClass =
        "Text";
      let view = view;
    }
  );

module ScrollView = {
  type callback = RNEvent.NativeScrollEvent.t => unit;
  external wrapUpdaterShamelessly : AnimatedRe.animatedEvent => callback = "%identity";
  let onScrollUpdater = (~x=?, ~y=?, ~native=false, ()) =>
    wrapUpdaterShamelessly(
      AnimatedRe.event(
        [|
          {
            "nativeEvent": {
              "contentOffset": {"x": Js.Undefined.from_opt(x), "y": Js.Undefined.from_opt(y)}
            }
          }
        |],
        {"useNativeDriver": Js.Boolean.to_js_boolean(native)}
      )
    );
  include
    ScrollView.CreateComponent(
      {
        [@bs.module "react-native"] [@bs.scope "AnimatedRe"] external view : ReasonReact.reactClass =
          "ScrollView";
        let view = view;
      }
    );
};
