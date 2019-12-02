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
}
