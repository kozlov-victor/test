import {VEngineTsxFactory} from "@engine/renderable/tsx/_genetic/vEngineTsxFactory.h";
import {Frame} from "./components/frame";
import {Reactive} from "@engine/renderable/tsx/decorator/reactive";
import {DomRootComponent} from "@engine/renderable/tsx/dom/domRootComponent";

export class MainWidget extends DomRootComponent {

    @Reactive.Method()
    private test(e:Event) {

    }


    render(): JSX.Element {
        return (
            <>
                <Frame title={'Pixel Font'}>
                    test 123
                </Frame>
            </>
        );
    }


}
