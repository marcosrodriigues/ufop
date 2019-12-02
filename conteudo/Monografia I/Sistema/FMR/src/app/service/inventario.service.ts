import { Injectable } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class InventarioService {

  constructor(private _http : HttpClient, 
              private _url : UrlService) { }

  private baseUrl : string = this._url.baseUrl() + "/inventario";

  getInventario() {
    return this._http.get(this.baseUrl);
  }

  save(answers) {
    return this._http.post(this.baseUrl, answers);
  }

}
