import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class PersonalidadeService {

  constructor(private _http : HttpClient, private _url : UrlService) { }

  private base_url : string = this._url.baseUrl() + "/personalidade";

  getPersonalidade() {
    return this._http.get(this.base_url);
  }

  setPercentage(person) {
    let percent : any = {};

    percent.abertura = this.round(person.abertura / 50 * 100, 2) + "%";
    percent.concordancia = this.round(person.concordancia / 45 * 100, 2) + "%";
    percent.consciencia = this.round(person.consciencia / 45 * 100, 2) + "%";
    percent.extroversao = this.round(person.extroversao / 40 * 100, 2) + "%";
    percent.neuroticismo = this.round(person.neuroticismo / 40 * 100, 2) + "%";

    return percent;
  }

  private round(value, exp) {
    return value.toFixed(exp);
  }
}
