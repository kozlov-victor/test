import {VEngineTsxFactory} from "@engine/renderable/tsx/_genetic/vEngineTsxFactory.h";
import {Frame} from "./components/frame";
import {Reactive} from "@engine/renderable/tsx/decorator/reactive";
import {DomRootComponent} from "@engine/renderable/tsx/dom/domRootComponent";
import {HttpClient} from "./httpClient";

export class MainWidget extends DomRootComponent {

    @Reactive.Property()
    private cnt = '0';

    @Reactive.Method()
    private async inc(e:Event) {
        let c = +this.cnt;
        c++;
        await HttpClient.post<void>('/preferences/cnt',{cnt:`${c}`});
        this.cnt = `${c}`;
    }


    override async onMounted() {
        super.onMounted();
        this.cnt = (await HttpClient.get<{cnt:string}>('/preferences/cnt')).cnt ?? '0';
    }

    render(): JSX.Element {
        return (
            <>
                <Frame title={'Привіт'}>
                    Ця html - сторінка працює на мікроконтролері ESP32.
                    <div>{this.cnt}</div>
                    <button onclick={this.inc}>click</button>
                </Frame>
            </>
        );
    }


}
